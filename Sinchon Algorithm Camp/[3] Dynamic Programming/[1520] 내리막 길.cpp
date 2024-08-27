#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007LL

ll R, C, debug_trial;
ll g[505][505], dp[505][505];
const ll dr[] = {0, 0, -1, 1}, dc[] {-1, 1, 0, 0};

ll rdp(ll r, ll c) {
  if (dp[r][c] != -1) return dp[r][c];
  dp[r][c] = 0;

  for (int i = 0; i < 4; i++) {
    ll nr = r + dr[i], nc = c + dc[i];
    if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
    if (g[r][c] >= g[nr][nc]) continue; 
    dp[r][c] += rdp(nr, nc);
  }

  return dp[r][c];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  memset(dp, -1, sizeof(dp));
  cin >> R >> C;
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      cin >> g[r][c];
    }
  }

  dp[0][0] = 1;
  cout << rdp(R - 1, C - 1);

  // Debug
  // for (int r = 0; r < R; r++) {
  //   for (int c = 0; c < C; c++) {
  //     cout << dp[r][c] << ' ';
  //   }
  //   cout << '\n';
  // }
}

// ■ check list ■
// 1. overflow, data type, memset. ==, >=, >
// 2. first visit, % MOD