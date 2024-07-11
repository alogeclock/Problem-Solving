#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

const int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
ll g[205][205], areas[105], cnt, area;
ll R, C, K;

void dfs(int r, int c) {
  area++; g[r][c] = 1;
  for (int i = 0; i < 4; i++) {
    ll nr = r + dr[i], nc = c + dc[i];
    if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
    if (g[nr][nc] == 0) dfs(nr, nc);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> C >> R >> K;
  for (int i = 0; i < K; i++) {
    // down-left row/col, up-right row/col
    ll lr, lc, rr, rc; cin >> lr >> lc >> rr >> rc;
    for (int r = lr; r < rr; r++) {
      for (int c = lc; c < rc; c++) {
        g[r][c] = 1;
      }
    }
  }

  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      if (g[r][c] == 0) {
        area = 0;
        dfs(r, c);
        areas[cnt++] = area; 
      }
    }
  }

  sort(areas, areas + cnt);

  cout << cnt << '\n';
  for (int i = 0; i < cnt; i++) {
    cout << areas[i] << '\n';
  }
}