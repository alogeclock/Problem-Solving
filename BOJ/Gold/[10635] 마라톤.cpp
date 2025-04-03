#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

ll point[505][2];
ll dst[505][505];
ll dp[505][505]; // [건너뛴 회수][이동한 체크포인트]

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  ll N, K; cin >> N >> K;

  for (int i = 1; i <= N; i++) {
    cin >> point[i][0] >> point[i][1];
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      ll dx = abs(point[i][0] - point[j][0]);
      ll dy = abs(point[i][1] - point[j][1]);
      dst[i][j] = dx + dy;
    }
  }

  memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 1; i <= N; i++) {
    dp[0][i] = dp[0][i-1] + dst[i-1][i];
  }

  for (int k = 1; k <= K; k++) { // K번 건너뛰기
    dp[k][1] = dp[k-1][1], dp[k][2] = dp[k-1][2];
    for (int e = 2; e <= N; e++) {   // 도착점
      for (int j = 0; j <= k; j++) { // 건너뛸 체크포인트 개수
        if (1 + j >= e) break; // 1에서 건너뛰어 도착점을 넘어간다면 종료
        dp[k][e] = min(dp[k-j][e-j-1] + dst[e-j-1][e], dp[k][e]);
      }
    }
  }
  
  cout << dp[K][N];
}