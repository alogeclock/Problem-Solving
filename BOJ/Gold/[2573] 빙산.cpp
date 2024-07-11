#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

ll pg[305][305], g[305][305], vst[305][305], R, C, year;
const int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
bool melt;

void dfs(int r, int c) {
  vst[r][c] = 1;

  for (int i = 0; i < 4; i++) {
    int nr = r + dr[i], nc = c + dc[i];
    if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
    if (g[nr][nc] && !vst[nr][nc]) dfs(nr, nc); 
  }
} 

void copy() {
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      pg[r][c] = g[r][c];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> R >> C;
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      cin >> g[r][c];
      pg[r][c] = g[r][c];
    }
  }

  // 매일 빙산을 녹이고, 방문 배열을 점검
  while (!melt) {
    year++, melt = 1;
    memset(vst, 0, sizeof(vst));

    for (int r = 0; r < R; r++) {
      for (int c = 0; c < C; c++) {
        if (g[r][c]) { // 빙산이 녹아 있지 않을 경우
          melt = 0;

          ll melt_amount = 0; // 이전 그래프를 통해 녹을 양 계산
          for (int i = 0; i < 4; i++) {
            ll nr = r + dr[i], nc = c + dc[i];
            if (!pg[nr][nc]) melt_amount++;
          }

          g[r][c] = max(g[r][c] - melt_amount, 0LL);
        }
      }
    }

    ll glacier_count = 0; // 빙산이 분리되었는지 확인
    for (int r = 0; r < R; r++) {
      for (int c = 0; c < C; c++) {
        if (g[r][c] && !vst[r][c]) glacier_count++, dfs(r, c);
      }
    }

    copy();
    
    if (glacier_count > 1) {
      cout << year;
      goto EXIT;
    }
  }

  cout << 0 << '\n';

  EXIT: return 0;
}