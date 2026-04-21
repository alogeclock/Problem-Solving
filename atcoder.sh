#!/bin/bash

# 인자(대회 이름)가 입력되지 않았을 때 안내 메시지
if [ -z "$1" ]; then
  echo "사용법: ./make_contest.sh [대회이름]"
  echo "예시: ./make_contest.sh abc300"
  exit 1
fi

# 소문자로 입력해도 대문자로 변환되도록 처리 (깔끔한 폴더 정리)
CONTEST_NAME=$(echo "$1" | tr '[:lower:]' '[:upper:]')

# 경로 설정
BASE_DIR="./AtCoder"
TEMPLATE_FILE="./template.cpp"
TARGET_DIR="$BASE_DIR/$CONTEST_NAME"

# template.cpp 파일이 있는지 확인
if [ ! -f "$TEMPLATE_FILE" ]; then
  echo "Error: '$TEMPLATE_FILE' 파일이 없습니다. 템플릿을 먼저 만들어주세요."
  exit 1
fi

# AtCoder 폴더와 대회 폴더 만들기 (-p 옵션으로 부모 폴더가 없으면 같이 생성)
mkdir -p "$TARGET_DIR"

# A번부터 F번까지 템플릿 코드 복사
for problem in A B C D E F; do
  cp "$TEMPLATE_FILE" "$TARGET_DIR/$problem.cpp"
done

echo "SUCCESS: '$TARGET_DIR' 폴더에 A.cpp ~ F.cpp 세팅이 완료되었습니다!"
