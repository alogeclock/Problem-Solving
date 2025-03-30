#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

/*
1) 마지막 자리는 1이다.
2) 0이 2개 이상 연속해서 나올 경우 앞에 1이 있어야 한다. 1을 찾지 못할 경우 제시한 패턴이 아니다.
3) 0으로 시작하는 문자열은 그 뒷자리가 1이다.

1) 앞에서부터 순회한다.
2) 첫 글자가 1일 경우 100+1+ 확인 모드에 들어간다.
  2-1) 0을 2개 이상 탐색하기 전 1이 등장 시 오류 처리한다.
  2-2) 0을 2개 이상 탐색한 후 1이 등장하면 1이 등장했음을 저장하고 모드를 유지한다.
  2-3) 1이 등장하다가 0이 등장하면 모드를 전환한다. 이 때 문자열이 종료하면 오류가 아니다.
3) 첫 글자가 0일 경우 01 확인 모드에 들어간다.
  3-1) 다음 글자가 1일 경우 모드를 -1로 초기화한다.
  3-2) 다음 글자가 0일 경우 오류 처리한다.
  3-3) 01 확인 모드 중에 문자열이 종료하면 오류다.
*/

ll mode = -1; // 0: 100+1+ 확인 모드 / 1: 01 확인 모드
ll mode0_zero = 0, mode0_one = 0; // mode0에서 0, 1의 수

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  ll T; cin >> T;
  for (int i = 0; i < T; i++) {
    bool flag = true; // 맞는 문자열인지 확인
    mode = -1, mode0_zero = 0, mode0_one = 0;
    string s; cin >> s;

    for (auto c : s) {
      if (mode == -1) {
        if (c == '1') mode = 0, mode0_zero = 0, mode0_one = 0;
        else if (c == '0') mode = 1, mode0_zero = 0, mode0_one = 0;
      }
      else if (mode == 0) { // 100+1+ 확인 모드
        if (mode0_zero < 2) {
          if (c == '1') goto FLAG_FALSE_SET; // 0 2개 이전에 1이 나오면 종료
          else mode0_zero++; // 주의: mode0_zero는 2 이상 증가하지 않음
        } 
        else { // 0이 2개 이상 등장
          if (c == '1') mode0_one++;
          else if (mode0_one == 1 && c == '0') 
            mode = 1, mode0_zero = 0, mode0_one = 0;
          else if (mode0_one > 1 && c == '0') {
            mode = 1, mode0_zero = 1, mode0_one = 0;
            // 모드 1로 상태를 초기화하되, 상태 데이터를 mode0 기준 '10'이 나왔다고 저장
            // ex) 10011111(1001), (10011111)(00)1: 모드 0으론 오답인데 1에선 정답일 수 있음
            // 정답이 되는 쪽으로 계산하다 둘 다 실패하면 에러로 이동해야 함
            // ex) 01 대신 00이 나왔는데, mode0_zero = 1, mode_one = 0이라면 mode1로 이동
          }
          // 0이 아직 등장하지 않는 경우는 무시
        }
      }
      else if (mode == 1) { // 01 확인 모드
        if (c == '1') mode = -1;
        else if (mode0_zero == 1 && mode0_one == 0) 
          mode = 0, mode0_zero = 2;
        else goto FLAG_FALSE_SET;
      }
    }

    // mode 1 실행 중 종료
    if (mode == 1) flag = false;
    // mode 0 실행 중 문자열을 완성하지 못하고 종료
    else if (mode == 0 && (mode0_zero < 2 || mode0_one == 0)) flag = false;
    
    PRINT_FLAG:
    cout << (flag ? "YES\n" : "NO\n");
    continue;

    FLAG_FALSE_SET:
    flag = false;
    goto PRINT_FLAG;
  }
}