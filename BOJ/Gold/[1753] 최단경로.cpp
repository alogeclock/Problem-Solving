// idea: dijkstra

#include <bits/stdc++.h>
#define MAX_VERTICES 20001
#define pii pair<int, int>
using namespace std;

// 두 정점 사이 여러 간선이 존재할 수 있음
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
    g[u].push_back({v, w}); // 다음 정점, 가중치
  }

  // min heap, 거리 기준 정렬
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, start}); // 거리, 정점
  dst[start] = 0;

  while (pq.size()) {
    auto [hdst, here] = pq.top(); // 거리, 정점
    pq.pop();

    // 현재 최단거리보다 멀면 무시 + 재방문 방지
    if (hdst > dst[here]) continue;

    /*
    for (int i = 0; i < g[here].size(); i++) {
      int next = g[here][i].first;
      int ndst = g[here][i].second + hdst;

      // next로 향하는 더 짧은 경로가 나왔을 때 pq에 투입
      if (dst[next] > ndst) {
        dst[next] = ndst;
        pq.push({ndst, next});
      }
    }
    */

    // 그래프는 정점, 거리로 입력받았기 떄문에 반대로 입력받음
    for (auto [next, ndst] : g[here]) {
      ndst += hdst;
      if (dst[next] > ndst) {
        dst[next] = ndst;
        pq.push({ndst, next}); // pq 입력은 거리, 정점
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