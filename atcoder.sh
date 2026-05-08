#!/bin/bash

# 인자가 입력되지 않았을 때 안내 메시지
if [ -z "$1" ]; then
  echo "사용법: ./make_contest.sh [대회이름]"
  echo "예시: ./make_contest.sh abc300"
  exit 1
fi

# 1. 입력받은 이름 그대로 소문자화 (폴더명용: abc-453)
CONTEST_DIR_NAME=$(echo "$1" | tr '[:upper:]' '[:lower:]')

# 2. 하이픈 제거 버전 생성 (AtCoder URL용: abc453)
CONTEST_ID=$(echo "$CONTEST_DIR_NAME" | sed 's/-//g')

# 경로 설정
BASE_DIR="./atcoder"
TEMPLATE_FILE="./template.cpp"
CONTEST_PATH="$BASE_DIR/$CONTEST_DIR_NAME"

# template.cpp 파일이 있는지 확인
if [ ! -f "$TEMPLATE_FILE" ]; then
  echo "Error: '$TEMPLATE_FILE' 파일이 없습니다. 템플릿을 먼저 만들어주세요."
  exit 1
fi

# A번부터 F번까지 각 폴더 생성 및 데이터 다운로드
for problem in A B C D E F; do
  PROBLEM_DIR="$CONTEST_PATH/$problem"
  
  # 각 폴더 생성 후 템플릿 파일 복사
  mkdir -p "$PROBLEM_DIR"
  TARGET_FILE="$PROBLEM_DIR/$problem.cpp"
  cp "$TEMPLATE_FILE" "$TARGET_FILE"
  
  # 3. oj-tools를 이용한 테스트 케이스 다운로드
  PROBLEM_URL="https://atcoder.jp/contests/${CONTEST_ID}/tasks/${CONTEST_ID}_${problem}"
  
  echo "--------------------------------------------------"
  echo "Downloading: $problem ($PROBLEM_URL)"
  
  # 해당 문제 폴더 내부의 test 폴더에 다운로드
  oj download "$PROBLEM_URL" -d "$PROBLEM_DIR/test"
done

echo "--------------------------------------------------"
echo "SUCCESS: '$CONTEST_PATH' 세팅 및 테스트 케이스 다운로드가 완료되었습니다!"