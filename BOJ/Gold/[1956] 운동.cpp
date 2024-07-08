// idea: floyd-warshall

/* [사이클 탐색]
자기 자신으로 이동할 수 있는 경로가 존재한다면, 
플로이드 워셜 알고리즘 이후 g[cur][cur]이 LINF보다 작은 값으로 갱신된다.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

ll g[405][405];
bool vst[405][405];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  memset(g, 0x3f, sizeof(g));

  ll V, E; cin >> V >> E;
  for (int i = 0; i < E; i++) {
    ll u, v, w; cin >> u >> v >> w;
    g[u][v] = w;
  }

  for (int k = 1; k <= V; k++) {
    for (int i = 1; i <= V; i++) {
      for (int j = 1; j <= V; j++) {
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }

  ll min_dist = LINF;
  for (int i = 1; i <= V; i++) {
    if (g[i][i] < LINF) min_dist = min(min_dist, g[i][i]);
  }

  if (min_dist == LINF) cout << -1;
  else cout << min_dist;
}