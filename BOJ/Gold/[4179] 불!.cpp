// idea: bfs

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

ll g[1010][1010], burn[1010][1010], vst[1010][1010];
ll R, C, cnt, area;
const int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
ll sr, sc;

struct Point {
  ll r, c, d;
  Point(ll r, ll c, ll d) : r(r), c(c), d(d) {}
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  memset(burn, 0x3f, sizeof(burn));
  queue<Point> q;

  cin >> R >> C;
  for (int r = 0; r < R; r++) {
    string s; cin >> s;
    for (int c = 0; c < C; c++) {
      if (s[c] == '#') g[r][c] = 1; // 벽
      else if (s[c] == '.') g[r][c] = 0; // 통로
      else if (s[c] == 'F') {
        q.push(Point(r, c, 0)); burn[r][c] = 0; // 큐에 불씨 삽입
      }
      else if (s[c] == 'J') sr = r, sc = c, vst[r][c] = 0;
    }
  }

  // 불이 번진 시각을 맵에 저장, 불이 여러 개 있을 수 있음
  while (q.size()) {
    ll cr = q.front().r, cc = q.front().c, cd = q.front().d;
    q.pop();

    for (int i = 0; i < 4; i++) {
      ll nr = cr + dr[i], nc = cc + dc[i], nd = cd + 1;
      if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
      if (g[nr][nc] == 1 || burn[nr][nc] <= nd) continue;
      burn[nr][nc] = nd;
      q.push(Point(nr, nc, nd));
    }
  }

  // 방문한 시각을 바탕으로 맵이 탔는지, 타지 않았는지 확인해 이동
  q.push(Point(sr, sc, 0));
  vst[sr][sc] = 1;

  ll ans = LINF;
  while (q.size()) {
    ll cr = q.front().r, cc = q.front().c, cd = q.front().d;
    q.pop();

    if (cr == 0 || cc == 0 || cr == R - 1 || cc == C - 1) {
      ans = min(ans, cd + 1);
      continue;
    }

    for (int i = 0; i < 4; i++) {
      ll nr = cr + dr[i], nc = cc + dc[i], nd = cd + 1;
      if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
      if (g[nr][nc] == 1 || nd >= burn[nr][nc] || vst[nr][nc] == 1) continue;

      vst[nr][nc] = 1;
      q.push(Point(nr, nc, nd));
    }
  }
  
  (ans == LINF) ? cout << "IMPOSSIBLE\n" : cout << ans;
}