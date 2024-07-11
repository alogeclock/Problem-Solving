// idea: bfs

/* 
다리: 한 섬의 가장자리를 시작점으로, 다른 섬의 가장자리를 끝점으로 하는 경로
관찰 1) brute-force: 모든 섬의 가장자리에 대해 다른 점까지의 이동거리 계산
관찰 2) 내 섬이 아닌 다른 육지 블록에 대한 최단 거리를 탐색

→ 도달한 블록이 내 섬이 아니라는 사실을 알 수 있어야 함, vst 맵으로 구현 가능

구현 1: brute-force
1) vst[] 배열을 통해 섬의 영역마다 섬 번호를 기록함
2) 한 점에 대해 모든 다른 점의 최단 거리를 구함 → O(N^4) = 1억 회
3) 모든 최단 거리 맵을 탐색, 
  if (육지 블록 && 내 섬이 아님) ans = min(ans, 최단 거리 맵[r][c])

→ 시간 복잡도도 간당간당하고, 메모리만 400MB가 필요

구현 2: 가장자리 블록만 저장
1) 육지 블록마다 4방향을 확인해서 맵에서 가장자리 블록만 따로 vector에 삽입
2) vector에 삽입된 블록에 대해서만 최단 거리 탐색
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

ll N, num, g[105][105], vst[105][105], dst[105][105];
const int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

void dfs(int r, int c) {
  vst[r][c] = num;
  for (int i = 0; i < 4; i++) {
    int nr = r + dr[i], nc = c + dc[i];
    if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
    if (g[nr][nc] && !vst[nr][nc]) dfs(nr, nc);
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

  vector<pll> v;
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      // 물과 접해 있는 가장자리 블록을 벡터에 삽입
      if (g[r][c] == 1) {
        bool flag = 0;
        for (int i = 0; i < 4; i++) {
          int nr = r + dr[i], nc = c + dc[i];
          if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
          if (g[nr][nc] == 0) flag = 1;
        }
        if (flag) v.push_back({r, c});
      }

      // vst 배열에 섬의 번호를 저장
      if (g[r][c] && !vst[r][c]) num++, dfs(r, c);
    }
  }

  // 벡터에 삽입된 모든 시작점에 대해 최단 거리 탐색
  ll ans = LINF;
  for (auto [sr, sc] : v) {
    memset(dst, 0x3f, sizeof(dst));
    queue<pll> q; q.push({sr, sc}); dst[sr][sc] = 0;
    ll sn = vst[sr][sc]; // 시작점의 섬 번호

    while (q.size()) {
      auto [cr, cc] = q.front();
      ll cn = vst[cr][cc], cdst = dst[cr][cc];
      q.pop();

      // 육지이고 다른 섬이면 다리 성립, 더 길어질 필요 없음
      if (g[cr][cc] && sn != vst[cr][cc]) ans = min(ans, cdst);

      for (int i = 0; i < 4; i++) {
        ll nr = cr + dr[i], nc = cc + dc[i], ndst = cdst + 1;
        if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
        if (ndst >= dst[nr][nc] || vst[nr][nc] == sn) continue;

        dst[nr][nc] = ndst;
        q.push({nr, nc});
      }
    }
  }
  
  cout << ans - 1;
}