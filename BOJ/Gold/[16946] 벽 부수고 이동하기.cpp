// idea: dp

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>r
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fint
#define PINF 1000000007

bool g[1010][1010];
int vst[1010][1010], dst[1010][1010];
const int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
int R, C, dist, cnt;

void dfs(int r, int c) {
  vst[r][c] = cnt, dist++;
  for (int i = 0; i < 4; i++) {
    int nr = r + dr[i], nc = c + dc[i];
    if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
    if (!g[nr][nc] && !vst[nr][nc]) dfs(nr, nc);
  }
}

void fill(int r, int c) {
  dst[r][c] = dist; 
  for (int i = 0; i < 4; i++) {
    int nr = r + dr[i], nc = c + dc[i];
    if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
    if (!g[nr][nc] && dst[nr][nc] == -1) fill(nr, nc);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  memset(dst, -1, sizeof(dst));

  cin >> R >> C;
  for (int r = 0; r < R; r++) {
    string s; cin >> s;
    for (int c = 0; c < C; c++) {
      g[r][c] = s[c] - '0';
    }
  }

  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      if (!g[r][c] && !vst[r][c]) {
        cnt++, dist = 0;
        dfs(r, c);
        dist %= 10;
        fill(r, c);
      }
    }
  }
  
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      if (g[r][c]) {
        int sum = 1; vector<int> v;
        for (int i = 0; i < 4; i++) {
          int nr = r + dr[i], nc = c + dc[i];
          if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;

          bool flag = false;
          for (auto k : v) if (k == vst[nr][nc]) flag = true;

          v.push_back(vst[nr][nc]);
          if (!flag && dst[nr][nc] != -1) sum += dst[nr][nc];
        }
        cout << sum % 10;
      }
      else cout << 0;
    }
    cout << '\n';
  }
}