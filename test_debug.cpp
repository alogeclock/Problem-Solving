// idea: bfs, graph dp

/*
1) 벽을 부수는 것은 낮, 밤에는 머물러 있을 수밖에 없는 경우가 존재
2) 머물러 있을 때가 최단 거리일 수 있다는 것은, vst 맵에 값을 저장할 수 없음을 의미
3) 튜플은 이동할 때 자신의 이동 거리를 저장하고 있어야 함
4) 낮과 밤의 행동을 구분, 밤에는 머무르기를 시도할 수 있지만, 낮에는 불가능
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007
#define NIGHT 0
#define NOON 1
#define STAY 4

ll R, C, K, g[1010][1010], vst[1010][1010][11];
const ll dr[] = {-1, 1, 0, 0, 0}, dc[] = {0, 0, -1, 1, 0};

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

  queue<tuple<ll, ll, ll, ll>> q;
  q.push({1, 1, 0, 1}); vst[1][1][0] = 1;

  while (q.size()) {
    auto [cr, cc, cj, cdst] = q.front();
    q.pop();

    if (cdst % 2 == NOON) {
      for (int i = 0; i < 4; i++) {
        ll nr = cr + dr[i], nc = cc + dc[i], nj = cj + 1, ndst = cdst + 1;
        if (nr <= 0 || nc <= 0 || nr > R || nc > C) continue;

        if (g[nr][nc] && ndst < vst[nr][nc][cj + 1] && nj <= K) // 벽 부수기
          vst[nr][nc][nj] = ndst, q.push({nr, nc, nj, ndst});
        else if (!g[nr][nc] && ndst < vst[nr][nc][cj]) // 통로 이동
          vst[nr][nc][cj] = ndst, q.push({nr, nc, cj, ndst});
      }
    }

    if (cdst % 2 == NIGHT) {
      for (int i = 0; i < 5; i++) {
        ll nr = cr + dr[i], nc = cc + dc[i], ndst = cdst + 1;
        if (nr <= 0 || nc <= 0 || nr > R || nc > C) continue;
        
        // 부순 벽이므로 무조건 머무를 수 있음
        if (i == STAY) q.push({nr, nc, cj, ndst});
        else if (!g[nr][nc] && ndst < vst[nr][nc][cj]) // 통로 이동 시 벽 확인
          vst[nr][nc][cj] = ndst, q.push({nr, nc, cj, ndst});
      }
    }
  }
  
  ll ans = LINF;
  for (int lv = 0; lv <= K; lv++) ans = min(ans, vst[R][C][lv]);
  (ans == LINF) ? cout << -1 : cout << ans;
}