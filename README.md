My Problem Solving Journey: BOJ, Programmers, AtCoder, etc.

### Atcoder Script 파일 자동 생성 및 테스트케이스 채점 방법

1. `./atcoder.sh {--copy/-c} abc-000`, 명령어 실행하여 문제별 파일 자동 생성 
2. 루트의 template.cpp를 복사하여 경로에 문제 파일이 자동 생성
3. `./atcoder.sh {--testcase/-t} ABC-000 A` 실행하여 예제 테스트케이스 자동 채점

### Jungol Script 파일 자동 생성 및 테스트케이스 채점 방법

1. `./jungol.py {--copy/-c} {문제번호/링크}`, 명령어 실행하여 문제별 파일 자동 생성 
2. 루트의 template.cpp를 복사하여 경로에 문제 파일이 자동 생성
3. `./jungol.py {--testcase/-t} {문제번호/링크}` 실행하여 예제 테스트케이스 자동 채점