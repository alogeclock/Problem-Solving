// idea: dp
// 조금 더 좋은 방법이 있지 않았을까?

#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF ((int)1e9 + 7)
#define ll long long

ll dp[1005][3][3];  // dp[길이][현재 길이의 장애물][직전 장애물]
ll _dp[1005][2][2];

struct Map {
  int mapLength, prevCactusSize, curCactusSize;
  Map(int l, int p, int c)
      : mapLength(l), prevCactusSize(p), curCactusSize(c){};
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T, N;
  cin >> T;

  N = T;
  dp[N][0][0] = dp[N][1][0] = dp[N][2][0] = 1;
  while (N > 1) {
    dp[N - 1][0][0] = (dp[N][0][0] + dp[N][0][1] + dp[N][0][2]) % PINF;
    dp[N - 1][0][1] = (dp[N][1][0] + dp[N][1][1] + dp[N][1][2]) % PINF;
    dp[N - 1][0][2] = (dp[N][2][0] + dp[N][2][1]) % PINF;

    dp[N - 1][1][0] = (dp[N][0][0] + dp[N][0][1] + dp[N][0][2]) % PINF;
    dp[N - 1][1][1] = dp[N][1][0] % PINF;
    dp[N - 1][1][2] = dp[N][2][0] % PINF;

    dp[N - 1][2][0] = (dp[N][0][0] + dp[N][0][1] + dp[N][0][2]) % PINF;
    dp[N - 1][2][1] = dp[N][1][0] % PINF;
    N--;
  }

  N = T;
  _dp[N][0][0] = _dp[N][1][0] = 1;
  while (N > 1) {
    _dp[N - 1][0][0] = (_dp[N][0][0] + _dp[N][0][1]) % PINF;
    _dp[N - 1][0][1] = (_dp[N][1][0] + _dp[N][1][1]) % PINF;

    _dp[N - 1][1][0] = (_dp[N][0][0] + _dp[N][0][1]) % PINF;
    _dp[N - 1][1][1] = _dp[N][1][0] % PINF;
    N--;
  }

  ll sum = 0;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) sum = (sum + dp[2][i][j]) % PINF;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) sum = (sum - _dp[2][i][j]) % PINF;

  sum = sum > 0 ? sum : PINF + sum;  // 음수일 시 양수화
  cout << sum % PINF;
}