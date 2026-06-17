#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
Usage:
  ./jungol.py --copy 1000
  ./jungol.py -c https://jungol.co.kr/problem/1000

  ./jungol.py --testcase 1000
  ./jungol.py -t https://jungol.co.kr/problem/1000

Notes:
  - 루트의 template.cpp를 복사해서 Jungol/{tier}/{problem_id}.cpp 생성
  - tier 폴더는 Bronze, Silver, Gold, Platinum, Diamond, Ruby 단위로만 생성
  - 생성 코드 맨 위에 // [Bronze 1] 1005. 가장 큰 소인수 형식 주석 삽입
  - Jungol 페이지에서 티어를 못 찾으면 Jungol/Unrated/{problem_id}.cpp 로 생성
  - -t 실행 시 매번 Jungol 페이지에서 예제 입력/출력을 다시 읽어 채점
"""

from __future__ import annotations

import argparse
import html
import os
import re
import subprocess
import sys
import tempfile
from dataclasses import dataclass
from pathlib import Path
from typing import Optional


ROOT = Path(__file__).resolve().parent
sys.path.insert(0, str(ROOT / ".python-packages"))

try:
    import requests
    from bs4 import BeautifulSoup, Tag
except ImportError:
    print("[ERROR] 필요한 패키지가 없습니다.")
    print("        sudo 없이 설치하려면:")
    print("        python3 -m pip install --target ./.python-packages requests beautifulsoup4")
    sys.exit(1)


BASE_URL = "https://jungol.co.kr/problem/{problem_id}"
TEMPLATE_CPP = ROOT / "template.cpp"
JUNGOL_DIR = ROOT / "Jungol"

CPP_COMPILER = os.environ.get("CXX", "g++")
CPP_FLAGS = [
    "-std=c++17",
    "-O2",
    "-pipe",
    "-Wall",
    "-Wextra",
]


@dataclass
class SampleCase:
    input_text: str
    output_text: str


@dataclass
class ProblemInfo:
    problem_id: str
    title: str
    tier: str          # 폴더용: Bronze, Silver, Gold...
    tier_detail: str   # 주석용: Bronze 1, Silver 3...
    samples: list[SampleCase]


def normalize_problem_arg(value: str) -> str:
    value = value.strip()

    match = re.search(r"/problem/(\d+)", value)
    if match:
        return match.group(1)

    if re.fullmatch(r"\d+", value):
        return value

    raise ValueError(f"문제 번호나 Jungol 문제 링크가 아닙니다: {value}")


def fetch_problem_html(problem_id: str) -> str:
    url = BASE_URL.format(problem_id=problem_id)

    headers = {
        "User-Agent": (
            "Mozilla/5.0 (Windows NT 10.0; Win64; x64) "
            "AppleWebKit/537.36 Chrome/125 Safari/537.36"
        ),
        "Accept-Language": "ko-KR,ko;q=0.9,en;q=0.8",
    }

    response = requests.get(url, headers=headers, timeout=15)
    response.raise_for_status()

    # Jungol 한글 깨짐 방지
    response.encoding = "utf-8"

    return response.text


def clean_text(text: str) -> str:
    text = html.unescape(text)
    text = text.replace("\xa0", " ")
    text = text.replace("\r\n", "\n").replace("\r", "\n")

    icon_words = [
        "login",
        "logout",
        "content_copy",
        "text_fields",
        "translate",
        "space_bar",
        "keyboard_return",
        "chevron_right",
    ]

    for word in icon_words:
        text = re.sub(rf"\b{re.escape(word)}\b", "", text)

    lines = [line.rstrip() for line in text.splitlines()]

    while lines and not lines[0].strip():
        lines.pop(0)
    while lines and not lines[-1].strip():
        lines.pop()

    return "\n".join(lines)


def compact_single_line(text: str) -> str:
    text = clean_text(text)
    text = re.sub(r"\s+", " ", text)
    return text.strip()


def sanitize_path_part(text: str) -> str:
    text = compact_single_line(text)
    text = re.sub(r'[\\/:*?"<>|]', "_", text)
    text = text.strip(". ")
    return text or "Unknown"


def parse_title_from_soup(soup: BeautifulSoup, problem_id: str) -> str:
    if soup.title and soup.title.string:
        title = compact_single_line(soup.title.string)
        title = re.sub(r"\s*-\s*JUNGOL\s*$", "", title, flags=re.I)
        if title:
            return title

    text = soup.get_text("\n")
    lines = [compact_single_line(x) for x in text.splitlines()]
    lines = [x for x in lines if x]

    for i, line in enumerate(lines):
        if f"#{problem_id}" in line:
            for nxt in lines[i + 1 : i + 8]:
                if nxt not in {"#", "문제"} and not nxt.startswith("#"):
                    nxt = re.sub(r"\btimer\b.*$", "", nxt).strip()
                    if nxt:
                        return nxt

    return f"Problem {problem_id}"


def tier_number_to_names(tier_number: int) -> tuple[str, str]:
    """
    1~5   : Bronze 5 ~ Bronze 1
    6~10  : Silver 5 ~ Silver 1
    11~15 : Gold 5 ~ Gold 1
    16~20 : Platinum 5 ~ Platinum 1
    21~25 : Diamond 5 ~ Diamond 1
    26~30 : Ruby 5 ~ Ruby 1
    """
    groups = [
        "Bronze",
        "Silver",
        "Gold",
        "Platinum",
        "Diamond",
        "Ruby",
    ]

    if tier_number < 1 or tier_number > 30:
        return "Unrated", "Unrated"

    group_index = (tier_number - 1) // 5
    level = 5 - ((tier_number - 1) % 5)

    folder_tier = groups[group_index]
    detail_tier = f"{folder_tier} {level}"

    return folder_tier, detail_tier


def parse_tier_from_soup(soup: BeautifulSoup) -> tuple[str, str]:
    """
    Jungol 난이도 아이콘 URL 예:
      https://s.jungol.co.kr/solved/18.svg?dm=jungol.co.kr

    18.svg -> ("Platinum", "Platinum 3")
    """
    for tag in soup.find_all(True):
        for attr_name in ["src", "data-src", "href", "data", "style"]:
            attr_value = tag.get(attr_name)
            if not attr_value:
                continue

            match = re.search(r"/solved/(\d+)\.svg", str(attr_value))
            if match:
                tier_number = int(match.group(1))
                return tier_number_to_names(tier_number)

    html_text = str(soup)
    match = re.search(r"/solved/(\d+)\.svg", html_text)
    if match:
        tier_number = int(match.group(1))
        return tier_number_to_names(tier_number)

    return "Unrated", "Unrated"


def get_heading_text(tag: Tag) -> str:
    return compact_single_line(tag.get_text(" "))


def remove_label_noise(text: str) -> str:
    lines = clean_text(text).splitlines()
    bad = {"입력", "출력", "content_copy", "login", "logout"}
    lines = [line for line in lines if compact_single_line(line) not in bad]
    return clean_text("\n".join(lines))


def is_sample_noise_line(line: str) -> bool:
    text = line.strip()
    if not text:
        return True

    noise = {
        "login",
        "logout",
        "content_copy",
        "text_fields",
        "translate",
        "chevron_right",
    }
    return text in noise


def decode_jungol_sample_lines(lines: list[str]) -> str:
    """
    Jungol 예제 영역은 실제 공백/개행을 Material Icon 텍스트로 끼워 넣는 경우가 있다.

      space_bar       -> 같은 줄의 공백
      keyboard_return -> 줄바꿈

    soup.get_text("\n")로 읽으면 DOM 노드 경계 때문에 0, space_bar, 1이 각각 다른 줄로
    갈라질 수 있다. 따라서 원본 줄바꿈을 곧바로 샘플 개행으로 보지 않고, 아이콘 토큰을
    기준으로 다시 조립한다.
    """
    cleaned_lines = []
    has_jungol_tokens = False

    for line in lines:
        line = html.unescape(line)
        line = line.replace("\xa0", " ")
        line = line.replace("\r\n", "\n").replace("\r", "\n")

        for subline in line.split("\n"):
            subline = subline.strip()
            if is_sample_noise_line(subline):
                continue
            if re.search(r"\b(?:space_bar|keyboard_return)\b", subline):
                has_jungol_tokens = True
            cleaned_lines.append(subline)

    if not cleaned_lines:
        return ""

    # 아이콘 토큰이 없는 평범한 pre/code 스타일 예제는 실제 줄바꿈을 그대로 보존한다.
    if not has_jungol_tokens:
        return clean_text("\n".join(cleaned_lines))

    output_lines: list[str] = []
    current = ""

    def flush_line() -> None:
        nonlocal current
        output_lines.append(current.rstrip())
        current = ""

    for line in cleaned_lines:
        # 한 줄 안에 "0 space_bar 1"처럼 들어온 경우와,
        # "0" / "space_bar" / "1"처럼 노드별로 갈라진 경우를 모두 처리한다.
        tokens = re.split(r"(\bspace_bar\b|\bkeyboard_return\b)", line)

        for token in tokens:
            if token == "":
                continue

            if token == "space_bar":
                current += " "
                continue

            if token == "keyboard_return":
                flush_line()
                continue

            # 토큰 주변의 DOM 구분용 공백은 제거하되, 토큰 내부 공백은 하나로 정리한다.
            token = re.sub(r"[ \t\f\v]+", " ", token).strip()
            if not token:
                continue
            current += token

    if current or not output_lines:
        flush_line()

    while output_lines and output_lines[0] == "":
        output_lines.pop(0)
    while output_lines and output_lines[-1] == "":
        output_lines.pop()

    return "\n".join(output_lines)


def parse_samples_by_jungol_text(soup: BeautifulSoup) -> list[SampleCase]:
    """
    Jungol v7 예제 영역을 줄 단위로 읽어서 입력/출력 블록을 분리한다.
    DOM 파서는 부모 컨테이너 전체를 잡기 쉬우므로, Jungol 페이지는 이 경로를 우선 사용한다.
    """
    raw_lines = soup.get_text("\n").splitlines()
    lines = [html.unescape(line).replace("\xa0", " ").strip() for line in raw_lines]
    lines = [line for line in lines if line]

    samples: list[SampleCase] = []
    i = 0

    def is_sample_header(text: str) -> bool:
        return re.fullmatch(r"예제(?:\s*#?\s*\d+)?", text) is not None

    def is_stop_header(text: str) -> bool:
        return (
            is_sample_header(text)
            or text in {"힌트", "태그", "출처"}
            or re.fullmatch(r"관련\s*문제|제출|채점|문제\s*목록|내\s*제출|댓글|소스|분류", text) is not None
        )

    while i < len(lines):
        if not is_sample_header(lines[i]):
            i += 1
            continue

        i += 1
        while i < len(lines) and lines[i] != "입력":
            if is_sample_header(lines[i]):
                break
            i += 1
        if i >= len(lines) or lines[i] != "입력":
            continue

        i += 1
        input_lines: list[str] = []
        while i < len(lines) and lines[i] != "출력":
            if is_stop_header(lines[i]):
                break
            input_lines.append(lines[i])
            i += 1
        if i >= len(lines) or lines[i] != "출력":
            continue

        i += 1
        output_lines: list[str] = []
        while i < len(lines) and not is_stop_header(lines[i]):
            output_lines.append(lines[i])
            i += 1

        input_text = decode_jungol_sample_lines(input_lines)
        output_text = decode_jungol_sample_lines(output_lines)
        if input_text and output_text:
            samples.append(SampleCase(input_text, output_text))

    return samples


def find_next_code_like_text(start: Tag) -> Optional[str]:
    node = start

    for _ in range(80):
        node = node.find_next()
        if node is None:
            break

        if not isinstance(node, Tag):
            continue

        node_text = get_heading_text(node)

        if node.name in {"h1", "h2", "h3", "h4"}:
            if re.search(r"예제\s*#?\s*\d+|힌트|태그|출처|문제|입력|출력", node_text):
                if node is not start:
                    break

        if node.name in {"pre", "code", "textarea"}:
            txt = clean_text(node.get_text("\n"))
            if txt:
                return txt

        if node_text in {"content_copy", "login", "logout", "입력", "출력"}:
            continue

        class_text = " ".join(node.get("class", [])).lower()
        if any(k in class_text for k in ["sample", "example", "code", "input", "output"]):
            txt = clean_text(node.get_text("\n"))
            txt = remove_label_noise(txt)
            if txt:
                return txt

    return None


def parse_samples_by_dom(soup: BeautifulSoup) -> list[SampleCase]:
    samples: list[SampleCase] = []

    headings = []
    for tag in soup.find_all(["h1", "h2", "h3", "h4", "strong", "b", "div", "span"]):
        txt = get_heading_text(tag)
        if re.fullmatch(r"예제\s*#?\s*\d+", txt) or re.search(r"예제\s*#?\s*\d+", txt):
            headings.append(tag)

    for heading in headings:
        input_text = None
        output_text = None

        node = heading
        for _ in range(120):
            node = node.find_next()
            if node is None or not isinstance(node, Tag):
                continue

            txt = get_heading_text(node)

            if node is not heading and re.search(r"예제\s*#?\s*\d+", txt):
                break

            if txt == "입력" or re.fullmatch(r".*\b입력\b.*", txt):
                input_text = find_next_code_like_text(node)

            if txt == "출력" or re.fullmatch(r".*\b출력\b.*", txt):
                output_text = find_next_code_like_text(node)

            if input_text is not None and output_text is not None:
                break

        if input_text is not None and output_text is not None:
            samples.append(SampleCase(input_text, output_text))

    return samples


def strip_explanation_tail(text: str) -> str:
    lines = [line for line in clean_text(text).splitlines() if line.strip()]

    kept = []
    for line in lines:
        s = line.strip()
        if len(kept) >= 1 and re.search(r"[가-힣]", s) and len(s) > 12:
            break
        kept.append(line)

    return clean_text("\n".join(kept))


def parse_samples_by_text(soup: BeautifulSoup) -> list[SampleCase]:
    # Jungol 신형 페이지 우선 처리.
    samples = parse_samples_by_jungol_text(soup)
    if samples:
        return samples

    # pre/code 기반 또는 구형 페이지 fallback.
    raw = soup.get_text("\n")
    raw = clean_text(raw)

    pattern = re.compile(
        r"예제(?:\s*#?\s*\d+)?\s*"
        r"(?:입력)?\s*(.*?)\s*"
        r"(?:출력)\s*(.*?)"
        r"(?=(?:예제(?:\s*#?\s*\d+)?)|(?:힌트)|(?:태그)|(?:출처)|\Z)",
        re.S,
    )

    samples: list[SampleCase] = []

    for match in pattern.finditer(raw):
        input_part = remove_label_noise(match.group(1))
        output_part = remove_label_noise(match.group(2))

        input_part = strip_explanation_tail(input_part)
        output_part = strip_explanation_tail(output_part)

        if input_part and output_part:
            samples.append(SampleCase(input_part, output_part))

    return samples


def parse_problem(problem_id: str) -> ProblemInfo:
    page_html = fetch_problem_html(problem_id)
    soup = BeautifulSoup(page_html, "html.parser")

    title = parse_title_from_soup(soup, problem_id)
    tier, tier_detail = parse_tier_from_soup(soup)

    # Jungol 예제는 공백/개행이 아이콘 토큰으로 표현되는 경우가 있어
    # 텍스트 파서를 먼저 사용한다. DOM 파서는 구형/pre 기반 페이지 fallback이다.
    samples = parse_samples_by_text(soup)
    if not samples:
        samples = parse_samples_by_dom(soup)

    return ProblemInfo(
        problem_id=problem_id,
        title=title,
        tier=tier,
        tier_detail=tier_detail,
        samples=samples,
    )


def get_problem_cpp_path(problem: ProblemInfo) -> Path:
    return JUNGOL_DIR / sanitize_path_part(problem.tier) / f"{problem.problem_id}.cpp"


def find_existing_cpp(problem: ProblemInfo) -> Path:
    expected = get_problem_cpp_path(problem)
    if expected.exists():
        return expected

    candidates = list(JUNGOL_DIR.glob(f"*/{problem.problem_id}.cpp"))
    if candidates:
        return candidates[0]

    raise FileNotFoundError(
        f"{problem.problem_id}.cpp 파일을 찾을 수 없습니다. 먼저 -c 옵션으로 생성하세요."
    )


def copy_template(problem: ProblemInfo, overwrite: bool = False) -> Path:
    if not TEMPLATE_CPP.exists():
        raise FileNotFoundError(f"template.cpp를 찾을 수 없습니다: {TEMPLATE_CPP}")

    dst = get_problem_cpp_path(problem)
    dst.parent.mkdir(parents=True, exist_ok=True)

    if dst.exists() and not overwrite:
        print(f"[SKIP] 이미 파일이 있습니다: {dst}")
        print("       덮어쓰려면 --force 옵션을 사용하세요.")
        return dst

    template_text = TEMPLATE_CPP.read_text(encoding="utf-8")

    if problem.tier_detail and problem.tier_detail != "Unrated":
        header = f"// [{problem.tier_detail}] {problem.problem_id}. {problem.title}\n"
    else:
        header = f"// {problem.problem_id}. {problem.title}\n"

    output_text = header + template_text

    dst.write_text(output_text, encoding="utf-8")
    print(f"[OK] 생성 완료: {dst}")
    return dst


def normalize_output(text: str) -> str:
    text = text.replace("\r\n", "\n").replace("\r", "\n")
    lines = [line.rstrip() for line in text.split("\n")]

    while lines and lines[-1] == "":
        lines.pop()

    return "\n".join(lines)


def format_block_for_log(text: str) -> str:
    # 채점용 normalize_output과 달리, 로그 가독성만 위한 포맷이다.
    # 줄바꿈은 보존하고 연속 빈 줄만 하나로 줄인다. 같은 줄의 공백은 건드리지 않는다.
    text = text.replace("\r\n", "\n").replace("\r", "\n")
    lines = [line.rstrip() for line in text.split("\n")]

    while lines and not lines[0].strip():
        lines.pop(0)
    while lines and not lines[-1].strip():
        lines.pop()

    compacted = []
    previous_blank = False
    for line in lines:
        if not line.strip():
            if not previous_blank:
                compacted.append("")
            previous_blank = True
        else:
            compacted.append(line)
            previous_blank = False

    return "\n".join(compacted)


def compile_cpp(source_path: Path, exe_path: Path) -> None:
    cmd = [
        CPP_COMPILER,
        *CPP_FLAGS,
        str(source_path),
        "-o",
        str(exe_path),
    ]

    print("[BUILD]", " ".join(cmd))

    result = subprocess.run(
        cmd,
        text=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
    )

    if result.returncode != 0:
        if result.stdout:
            print(result.stdout)
        if result.stderr:
            print(result.stderr)
        raise RuntimeError("컴파일 실패")


def run_one_sample(exe_path: Path, sample: SampleCase, index: int) -> bool:
    result = subprocess.run(
        [str(exe_path)],
        input=sample.input_text,
        text=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        timeout=5,
    )

    actual = normalize_output(result.stdout)
    expected = normalize_output(sample.output_text)

    ok = result.returncode == 0 and actual == expected

    print(f"\n[Sample #{index}] {'PASS' if ok else 'FAIL'}")

    if result.stderr.strip():
        print("[stderr]")
        print(result.stderr.rstrip())

    if not ok:
        print("[input]")
        print(format_block_for_log(sample.input_text))
        print("[expected]")
        print(format_block_for_log(expected))
        print("[actual]")
        print(format_block_for_log(actual))
        print(f"[returncode] {result.returncode}")

    return ok


def testcase(problem: ProblemInfo) -> None:
    if not problem.samples:
        raise RuntimeError("예제 테스트케이스를 찾지 못했습니다.")

    source_path = find_existing_cpp(problem)

    with tempfile.TemporaryDirectory() as td:
        exe_name = "main.exe" if os.name == "nt" else "main"
        exe_path = Path(td) / exe_name

        compile_cpp(source_path, exe_path)

        passed = 0
        total = len(problem.samples)

        for i, sample in enumerate(problem.samples, start=1):
            if run_one_sample(exe_path, sample, i):
                passed += 1

        print(f"\n[RESULT] {passed}/{total} passed")

        if passed != total:
            sys.exit(1)


def print_problem_info(problem: ProblemInfo) -> None:
    print(f"[INFO] #{problem.problem_id} {problem.title}")
    print(f"[INFO] tier: {problem.tier_detail}")
    print(f"[INFO] folder: {problem.tier}")
    print(f"[INFO] samples: {len(problem.samples)}")


def main() -> None:
    parser = argparse.ArgumentParser(
        prog="jungol.py",
        description="Jungol 문제 템플릿 생성 및 예제 테스트 자동 실행 스크립트",
    )

    group = parser.add_mutually_exclusive_group(required=True)

    group.add_argument(
        "-c",
        "--copy",
        metavar="LINK_OR_ID",
        help="문제 번호 또는 Jungol 문제 링크를 읽고 template.cpp 복사",
    )

    group.add_argument(
        "-t",
        "--testcase",
        metavar="LINK_OR_ID",
        help="문제 번호 또는 Jungol 문제 링크의 예제 테스트 자동 실행",
    )

    parser.add_argument(
        "-f",
        "--force",
        action="store_true",
        help="--copy 시 기존 파일 덮어쓰기",
    )

    args = parser.parse_args()
    target = args.copy or args.testcase

    try:
        problem_id = normalize_problem_arg(target)
        problem = parse_problem(problem_id)
        print_problem_info(problem)

        if args.copy:
            copy_template(problem, overwrite=args.force)
        elif args.testcase:
            testcase(problem)

    except KeyboardInterrupt:
        print("\n[ERROR] interrupted")
        sys.exit(130)
    except Exception as e:
        print(f"[ERROR] {e}")
        sys.exit(1)


if __name__ == "__main__":
    main()