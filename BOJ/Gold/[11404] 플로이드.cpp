// idea: floyd-warshall
// x → y의 비용과 x → z → y의 비용(z를 거쳐 가는 비용) 비교

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int V, E;
  cin >> V >> E;

  vector<vector<long long>> g(V + 1, vector<long long>(V + 1, 1e18));

  int u, v, w;
  for (int i = 0; i < E; i++) {
    cin >> u >> v >> w;
    if (g[u][v] > w) g[u][v] = w;
  }

  for (int k = 1; k <= V; k++)    // 거쳐 가는 노드가 기준
    for (int i = 1; i <= V; i++)  // 출발, 도착 : i, j
      for (int j = 1; j <= V; j++) {
        if (g[i][j] > g[i][k] + g[k][j]) g[i][j] = g[i][k] + g[k][j];
      }

  for (int i = 1; i <= V; i++) {
    for (int j = 1; j <= V; j++) {
      if (g[i][j] == 1e18 || i == j)
        cout << "0 ";
      else
        cout << g[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}