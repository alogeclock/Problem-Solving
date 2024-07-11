#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

const ll dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
ll g[1010][1010], burn[1010][1010], vst[1010][1010];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll T; cin >> T;
  while (T--) {
    memset(g, 0, sizeof(g));
    memset(burn, 0x3f, sizeof(burn));
    memset(vst, 0x3f, sizeof(vst));

    ll R, C; cin >> C >> R;
    ll sr, sc; // start_row, start_col;
    queue<pll> q;
    for (int r = 0; r < R; r++) {
      string s; cin >> s;
      for (int c = 0; c < C; c++) {
        (s[c] == '.') ? g[r][c] = 0 : g[r][c] = 1;
        if (s[c] == '@') sr = r, sc = c, vst[r][c] = 1;
        if (s[c] == '*') burn[r][c] = 1, q.push({r, c});
      }
    }

    // find the burnt time of tile
    while (q.size()) {
      auto [cr, cc] = q.front();
      ll cdst = burn[cr][cc];
      q.pop();

      for (int i = 0; i < 4; i++) {
        ll nr = cr + dr[i], nc = cc + dc[i], ndst = cdst + 1;
        if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
        if (g[nr][nc] == 1 || ndst >= burn[nr][nc]) continue;

        burn[nr][nc] = ndst;
        q.push({nr, nc});
      }
    }

    ll ans = LINF; q.push({sr, sc});
    // find the fastest time of exit the building
    while (q.size()) {
      auto [cr, cc] = q.front();
      ll cdst = vst[cr][cc];
      q.pop();

      if (cr == 0 || cc == 0 || cr == R - 1 || cc == C - 1)
        ans = min(ans, cdst);

      for (int i = 0; i < 4; i++) {
        ll nr = cr + dr[i], nc = cc + dc[i], ndst = cdst + 1;
        if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
        if (ndst >= burn[nr][nc]) continue;
        if (g[nr][nc] == 1 || ndst >= vst[nr][nc]) continue;

        vst[nr][nc] = ndst;
        q.push({nr, nc});
      }
    }
    
    (ans < LINF) ? cout << ans << '\n' : cout << "IMPOSSIBLE\n";
  }
}