// idea: bfs, graph dp

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

ll R, C, K, g[1010][1010], vst[1010][1010][11];
const ll dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  memset(vst, 0x3f, sizeof(vst));

  cin >> R >> C >> K;
  for (int r = 0; r < R; r++) {
    string s; cin >> s;
    for (int c = 0; c < C; c++) {
      g[r + 1][c + 1] = s[c] - '0';
    }
  }

  queue<tuple<ll, ll, ll>> q; q.push({1, 1, 0}); vst[1][1][0] = 1;
  while (q.size()) {
    auto [cr, cc, cj] = q.front();
    ll cdst = vst[cr][cc][cj];
    q.pop();

    for (int i = 0; i < 4; i++) {
      ll nr = cr + dr[i], nc = cc + dc[i], nj = cj + 1, ndst = cdst + 1;
      if (nr <= 0 || nc <= 0 || nr > R || nc > C) continue;
      
      if (g[nr][nc] && ndst < vst[nr][nc][cj + 1] && nj <= K) // 벽 부수기
        vst[nr][nc][nj] = ndst, q.push({nr, nc, nj});
      else if (!g[nr][nc] && ndst < vst[nr][nc][cj]) // 통로 이동
        vst[nr][nc][cj] = ndst, q.push({nr, nc, cj});
    }
  }
  
  ll ans = LINF;
  for (int lv = 0; lv <= K; lv++) ans = min(ans, vst[R][C][lv]);
  (ans == LINF) ? cout << -1 : cout << ans;
}