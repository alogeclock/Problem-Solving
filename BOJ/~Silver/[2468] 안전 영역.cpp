#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

ll N, ans, area, g[105][105], vst[105][105];
const ll dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

void dfs(int r, int c, int h) {
  vst[r][c] = 1;

  for (int i = 0; i < 4; i++) {
    int nr = r + dr[i], nc = c + dc[i];
    if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
    if (g[nr][nc] <= h || vst[nr][nc] == 1) continue;

    dfs(nr, nc, h);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> N;
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      cin >> g[r][c];
    }
  }
  
  // O(N^3), brute-force로도 충분히 통과 가능
  for (int h = 0; h < 100; h++) {
    memset(vst, 0, sizeof(vst));
    area = 0;
    for (int r = 0; r < N; r++) {
      for (int c = 0; c < N; c++) {
        if (g[r][c] > h && !vst[r][c]) area++, dfs(r, c, h);
      }
    }
    ans = max(ans, area);
  }

  cout << ans;
}