#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

struct Point {
  int l, r, c;
  Point(int l, int r, int c) : l(l), r(r), c(c) {}
};

const int dir[6][3] = {{0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};
ll g[33][33][33], vst[33][33][33];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  while (true) {
    ll L, R, C; cin >> L >> R >> C;
    if (!L && !R && !C) break;

    memset(g, 0, sizeof(g));
    memset(vst, 0x3f, sizeof(vst));
    ll sl, sr, sc, el, er, ec;

    for (int l = 0; l < L; l++) {
      for (int r = 0; r < R; r++) {
        string s; cin >> s;
        for (int c = 0; c < C; c++) {
          if (s[c] == '#') g[l][r][c] = 1;
          else g[l][r][c] = 0;
          if (s[c] == 'S') sl = l, sr = r, sc = c;
          if (s[c] == 'E') el = l, er = r, ec = c;         
        }
      }
    }

    queue<Point> q; q.push(Point(sl, sr, sc)); 
    vst[sl][sr][sc] = 1;

    while (q.size()) {
      int cl = q.front().l, cr = q.front().r, cc = q.front().c;
      int cdst = vst[cl][cr][cc];
      q.pop();

      for (int i = 0; i < 6; i++) {
        int nl = cl + dir[i][0], nr = cr + dir[i][1], nc = cc + dir[i][2];
        int ndst = cdst + 1;

        if (nl < 0 || nl >= L || nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
        if (vst[nl][nr][nc] <= ndst || g[nl][nr][nc]) continue;

        vst[nl][nr][nc] = ndst;
        q.push(Point(nl, nr, nc));
      }
    }

    if (vst[el][er][ec] != LINF) 
      cout << "Escaped in " << vst[el][er][ec] - 1 << " minute(s).\n";
    else cout << "Trapped!\n";
  }  
}