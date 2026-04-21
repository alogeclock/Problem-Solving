My Problem Solving Journey: BOJ, Programmers, AtCoder, etc.

### Atcoder Script 파일 자동 생성 및 테스트케이스 채점 방법

1. ./atcoder.sh ABC-453 스크립트를 실행하여 문제별 파일 자동 생성
2. oj d https://atcoder.jp/contests/abc453/tasks/abc453_a 입력하여 문제 페이지의 예제 입출력 다운로드
3. gt++ A.cpp -o out: 코드 작성 및 컴파일
4. oj t -c "./out": 테스트 케이스 실행 및 결과 확인
