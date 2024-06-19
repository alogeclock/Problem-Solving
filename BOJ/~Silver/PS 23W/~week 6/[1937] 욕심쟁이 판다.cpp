// idea: graph dp(지도를 만들고, 방문을 기록한 뒤, 재귀로 저장)
// debugging: 경계값 조심, 크거나 같다/크다, off-by-one error

#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 1)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long

const int dr[] = {-1, 0, 1, 0}, dc[] = {0, -1, 0, 1};
int forest[505][505];
int dp[505][505];
int N;

int rdp(int r, int c) {
  if (dp[r][c]) return dp[r][c];

  dp[r][c] = 1;  // 방문 초기화
  for (int k = 0; k < 4; k++) {
    int nr = r + dr[k], nc = c + dc[k];

    if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
    if (forest[nr][nc] <= forest[r][c]) continue;

    dp[r][c] = max(dp[r][c], rdp(nr, nc) + 1);
  }

  return dp[r][c];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) cin >> forest[i][j];

  int ans = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) ans = max(ans, rdp(i, j));

  cout << ans;
}