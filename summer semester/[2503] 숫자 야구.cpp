// idea: brute-force, implementation
// brute-force → backtracking 풀이

#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define PINF 1000000007

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N;
  cin >> N;

  string s[105];
  int strike[105], ball[105];

  for (int i = 0; i < N; i++) {
    cin >> s[i] >> strike[i] >> ball[i];
  }

  int ans = 0;

  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      for (int k = 1; k < 10; k++) {
        if (i == j || i == k || j == k) continue;
        int flag = true;

        map<int, int> num;
        num[i] = 1, num[j] = 2, num[k] = 3;

        for (int t = 0; t < N; t++) {  // test 회수 (< 100)
          // strike, ball 수 세고, 같으면 진행
          int t_strike = 0, t_ball = 0;
          for (int p = 0; p < 3; p++) {
            if (num[s[t][p] - 48] == 0) continue;
            if (num[s[t][p] - 48] == p + 1)
              t_strike++;
            else
              t_ball++;
          }
          if (t_strike == strike[t] && t_ball == ball[t]) continue;

          // 같지 않으면 종료
          flag = false;
          break;
        }

        if (flag) ans++;  // test 전부 통과 시 답안++
      }
    }
  }

  cout << ans;
}