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
  - 생성 코드 맨 위에 // {문제 번호}. {문제 이름} 주석 삽입
  - Jungol 페이지에서 티어를 못 찾으면 Jungol/Unrated/{problem_id}.cpp 로 생성
  - 샘플 테스트케이스는 cpp 옆에 Jungol/{tier}/{problem_id}.testcase 로 저장
  - -t 실행 시 기본적으로 웹에 다시 접속하지 않고 .testcase 파일만 사용
  - --refresh 옵션을 주면 Jungol 페이지에서 다시 다운로드
"""

from __future__ import annotations

import argparse
import html
import json
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
    sys.exit(1)


BASE_URL = "https://jungol.co.kr/problem/{problem_id}"
TEMPLATE_CPP = ROOT / "template.cpp"
JUNGOL_DIR = ROOT / "Jungol"
GITIGNORE = ROOT / ".gitignore"

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
    tier: str
    samples: list[SampleCase]


def normalize_problem_arg(value: str) -> str:
    """
    1000, /problem/1000, https://jungol.co.kr/problem/1000 모두 지원.
    """
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


def tier_number_to_name(tier_number: int) -> str:
    groups = [
        "Bronze",
        "Silver",
        "Gold",
        "Platinum",
        "Diamond",
        "Ruby",
    ]

    if tier_number < 1 or tier_number > 30:
        return "Unrated"

    group_index = (tier_number - 1) // 5
    level = 5 - ((tier_number - 1) % 5)

    return f"{groups[group_index]}_{level}"


def parse_tier_from_soup(soup: BeautifulSoup) -> str:
    """
    Jungol 난이도 아이콘 URL 예:
      https://s.jungol.co.kr/solved/18.svg?dm=jungol.co.kr

    여기서 18을 뽑아 Platinum_3으로 변환.
    """
    # 1. img, source, object 등의 src/data 속성에서 우선 탐색
    for tag in soup.find_all(True):
        for attr_name in ["src", "data-src", "href", "data", "style"]:
            attr_value = tag.get(attr_name)
            if not attr_value:
                continue

            match = re.search(r"/solved/(\d+)\.svg", str(attr_value))
            if match:
                tier_number = int(match.group(1))
                return tier_number_to_name(tier_number)

    # 2. HTML 전체 문자열에서 fallback 탐색
    html_text = str(soup)
    match = re.search(r"/solved/(\d+)\.svg", html_text)
    if match:
        tier_number = int(match.group(1))
        return tier_number_to_name(tier_number)

    return "Unrated"


def get_heading_text(tag: Tag) -> str:
    return compact_single_line(tag.get_text(" "))


def remove_label_noise(text: str) -> str:
    lines = clean_text(text).splitlines()
    bad = {"입력", "출력", "content_copy", "login", "logout"}
    lines = [line for line in lines if compact_single_line(line) not in bad]
    return clean_text("\n".join(lines))


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
    """
    DOM 파싱 실패 시 fallback.
    """
    raw = soup.get_text("\n")
    raw = clean_text(raw)

    pattern = re.compile(
        r"예제\s*#?\s*(\d+)\s*"
        r"(?:입력)?\s*(.*?)\s*"
        r"(?:출력)\s*(.*?)"
        r"(?=(?:예제\s*#?\s*\d+)|(?:힌트)|(?:태그)|(?:출처)|\Z)",
        re.S,
    )

    samples: list[SampleCase] = []

    for match in pattern.finditer(raw):
        input_part = remove_label_noise(match.group(2))
        output_part = remove_label_noise(match.group(3))

        input_part = strip_explanation_tail(input_part)
        output_part = strip_explanation_tail(output_part)

        if input_part and output_part:
            samples.append(SampleCase(input_part, output_part))

    return samples


def parse_problem(problem_id: str) -> ProblemInfo:
    page_html = fetch_problem_html(problem_id)
    soup = BeautifulSoup(page_html, "html.parser")

    title = parse_title_from_soup(soup, problem_id)
    tier = parse_tier_from_soup(soup)

    samples = parse_samples_by_dom(soup)
    if not samples:
        samples = parse_samples_by_text(soup)

    return ProblemInfo(
        problem_id=problem_id,
        title=title,
        tier=tier,
        samples=samples,
    )


def get_problem_cpp_path(problem: ProblemInfo) -> Path:
    return JUNGOL_DIR / sanitize_path_part(problem.tier) / f"{problem.problem_id}.cpp"


def get_problem_testcase_path(problem: ProblemInfo) -> Path:
    return get_problem_cpp_path(problem).with_suffix(".testcase")


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


def find_existing_testcase_path(problem_id: str) -> Optional[Path]:
    candidates = list(JUNGOL_DIR.glob(f"*/{problem_id}.testcase"))
    if candidates:
        return candidates[0]
    return None


def ensure_gitignore_entry(entry: str) -> None:
    existing = ""

    if GITIGNORE.exists():
        existing = GITIGNORE.read_text(encoding="utf-8", errors="ignore")

    lines = {line.strip() for line in existing.splitlines()}

    if entry not in lines:
        with GITIGNORE.open("a", encoding="utf-8") as f:
            if existing and not existing.endswith("\n"):
                f.write("\n")
            f.write(f"{entry}\n")

        print(f"[OK] .gitignore 추가: {entry}")


def save_problem_cache(problem: ProblemInfo) -> None:
    testcase_path = get_problem_testcase_path(problem)
    testcase_path.parent.mkdir(parents=True, exist_ok=True)

    data = {
        "problem_id": problem.problem_id,
        "title": problem.title,
        "tier": problem.tier,
        "url": BASE_URL.format(problem_id=problem.problem_id),
        "samples": [
            {
                "input": sample.input_text,
                "output": sample.output_text,
            }
            for sample in problem.samples
        ],
    }

    testcase_path.write_text(
        json.dumps(data, ensure_ascii=False, indent=2),
        encoding="utf-8",
    )

    ensure_gitignore_entry("*.testcase")

    print(f"[OK] 테스트케이스 저장: {testcase_path}")


def load_problem_cache(problem_id: str) -> Optional[ProblemInfo]:
    testcase_path = find_existing_testcase_path(problem_id)

    if testcase_path is None or not testcase_path.exists():
        return None

    data = json.loads(testcase_path.read_text(encoding="utf-8"))

    samples = [
        SampleCase(
            input_text=str(sample.get("input", "")),
            output_text=str(sample.get("output", "")),
        )
        for sample in data.get("samples", [])
    ]

    return ProblemInfo(
        problem_id=str(data.get("problem_id", problem_id)),
        title=str(data.get("title", f"Problem {problem_id}")),
        tier=str(data.get("tier", "Unrated")),
        samples=samples,
    )


def load_problem(problem_id: str, use_cache: bool = True, allow_web: bool = True) -> ProblemInfo:
    if use_cache:
        cached = load_problem_cache(problem_id)
        if cached is not None:
            print(f"[CACHE] testcase 파일에서 문제 정보 로드: #{problem_id}")
            return cached

    if not allow_web:
        raise FileNotFoundError(
            f"{problem_id}.testcase 파일을 찾지 못했습니다.\n"
            f"먼저 ./jungol.py -c {problem_id} 를 실행하세요."
        )

    problem = parse_problem(problem_id)
    save_problem_cache(problem)
    return problem


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
        print(sample.input_text)
        print("[expected]")
        print(expected)
        print("[actual]")
        print(actual)
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

    parser.add_argument(
        "--refresh",
        action="store_true",
        help="기존 .testcase 캐시를 무시하고 Jungol 페이지에서 다시 다운로드",
    )

    args = parser.parse_args()

    target = args.copy or args.testcase

    try:
        problem_id = normalize_problem_arg(target)

        if args.copy:
            problem = load_problem(
                problem_id,
                use_cache=not args.refresh,
                allow_web=True,
            )

            print(f"[INFO] #{problem.problem_id} {problem.title}")
            print(f"[INFO] tier: {problem.tier}")
            print(f"[INFO] samples: {len(problem.samples)}")

            copy_template(problem, overwrite=args.force)

            # 캐시에서 읽은 경우에도 gitignore 보장
            ensure_gitignore_entry("*.testcase")

        elif args.testcase:
            problem = load_problem(
                problem_id,
                use_cache=not args.refresh,
                allow_web=args.refresh,
            )

            print(f"[INFO] #{problem.problem_id} {problem.title}")
            print(f"[INFO] tier: {problem.tier}")
            print(f"[INFO] samples: {len(problem.samples)}")

            testcase(problem)

    except KeyboardInterrupt:
        print("\n[ERROR] interrupted")
        sys.exit(130)
    except Exception as e:
        print(f"[ERROR] {e}")
        sys.exit(1)


if __name__ == "__main__":
    main()