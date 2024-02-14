// idea: dp

#include <bits/stdc++.h>
using namespace std;

// dp[a][b] 고른 사탕 상자 수는 a개, 300으로 나누었을때
// 나머지가 b가 되도록 고를 때 가져갈 수 있는 최대 사탕 개수
int dp[301][300];
int candy[300];
int n, m, k;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;

  for (int i = 0; i < n; i++) {
    cin >> candy[i];
    dp[1][candy[i] % k] = max(dp[1][candy[i] % k], candy[i]);
    // 나머지가 b가 되도록 고를 때 가져갈 수 있는 최대 사탕 수, 종류별로 고름
  }

  for (int i = 2; i <= m; i++) {  // 사탕을 고를 수 있는 회수
    for (int j = 0; j < k; j++) {  // 이전에 나머지가 j가 되도록 고른 경우들
      if (dp[i - 1][j] == 0) continue;
      for (int x = 0; x < n; x++) {
        dp[i][(j + candy[x]) % k] =
            max(dp[i - 1][j] + candy[x], dp[i][(j + candy[x]) % k]);
        // 캔디를 종류별로 고르고, 나머지에 따라 분류해서 최대값을 구함
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= m; i++) {
    ans = max(dp[i][0], ans);
  }
  cout << ans;
  return 0;
}