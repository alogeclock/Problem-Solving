// idea: bfs

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

ll K, R, C;
ll g[205][205], vst[205][205][31];
const ll dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
const ll mr[] = {-2, -2, -1, -1, 1, 1, 2, 2}, mc[] = {-1, 1, -2, 2, -2, 2, -1, 1};

struct Point {
  int r, c, j;
  Point(int r, int c, int j) : r(r), c(c), j(j) {}
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  memset(vst, 0x3f, sizeof(vst));

  cin >> K >> C >> R;
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      cin >> g[r][c];
    }
  }

  queue<Point> q; q.push({0, 0, 0}); vst[0][0][0] = 0;
  while (q.size()) {
    auto [cr, cc, cj] = q.front();
    ll cdst = vst[cr][cc][cj];
    q.pop();

    for (int i = 0; i < 4; i++) {
      ll nr = cr + dr[i], nc = cc + dc[i], ndst = cdst + 1;
      if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
      if (g[nr][nc] || vst[nr][nc][cj] <= ndst) continue;
      vst[nr][nc][cj] = ndst;
      q.push(Point(nr, nc, cj));
    }

    if (cj >= K) continue;

    for (int i = 0; i < 8; i++) {
      ll nr = cr + mr[i], nc = cc + mc[i];
      ll nj = cj + 1, ndst = cdst + 1;
      if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
      if (g[nr][nc] || vst[nr][nc][nj] <= ndst) continue;
      vst[nr][nc][nj] = ndst;
      q.push(Point(nr, nc, nj));
    }
  }

  ll ans = LINF;
  for (int lv = 0; lv <= K; lv++) ans = min(ans, vst[R - 1][C - 1][lv]);
  (ans == LINF) ? cout << "-1\n" : cout << ans;
}