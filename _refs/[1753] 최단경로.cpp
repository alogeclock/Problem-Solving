// idea: dijkstra

#include <bits/stdc++.h>
#define MAX_VERTICES 20001
#define pii pair<int, int>
using namespace std;

vector<vector<pii>> g(MAX_VERTICES);
vector<int> dst(MAX_VERTICES, 1e9);

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int V, E, start;
  cin >> V >> E >> start;

  for (int i = 0; i < E; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
  }

  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, start});
  dst[start] = 0;

  while (pq.size()) {
    auto [hdst, here] = pq.top(); // 거리 기준 우선순위 큐
    pq.pop();
    if (hdst > dst[here]) continue;
    for (auto [next, ndst] : g[here]) {
      ndst += hdst;
      if (dst[next] > ndst) {
        dst[next] = ndst;
        pq.push({ndst, next});
      }
    }
  }

  for (int i = 1; i <= V; i++) {
    if (dst[i] == 1e9)
      cout << "INF\n";
    else
      cout << dst[i] << '\n';
  }

  return 0;
}