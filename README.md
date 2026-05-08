My Problem Solving Journey: BOJ, Programmers, AtCoder, etc.

### Atcoder Script 파일 자동 생성 및 테스트케이스 채점 방법

1. "./atcoder.sh ABC-453" 스크립트를 실행하여 문제별 파일 자동 생성
2. 각 폴더에서 "oj d https://atcoder.jp/contests/abc453/tasks/abc453_a" 입력하여 문제 페이지의 예제 입출력 다운로드
3. g++ A.cpp -o A: 코드 작성 및 컴파일
4. oj t -c "./A": 테스트 케이스 실행 및 결과 확인

### Jungol Script 파일 자동 생성 및 테스트케이스 채점 방법

1. `./jungol.py {--copy/-c} {문제번호/링크}`, 명령어 실행하여 문제별 파일 자동 생성 
2. 루트의 template.cpp를 복사하여 경로에 문제 파일 생성
3. `./jungol.py {--testcase/-t} {문제번호/링크}` 실행하여 예제 테스트케이스 자동 채점