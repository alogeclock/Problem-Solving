#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int next, dst;
  Edge(int v, int w) : next(v), dst(w){};
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int V, E;
  cin >> V >> E;

  vector<vector<Edge>> g(V + 1);
  bool *memo = new bool(V + 1);

  int u, v, w;
  for (int i = 0; i < E; i++) {
    cin >> u >> v >> w;
    g[u].push_back(Edge(v, w));
    g[v].push_back(Edge(u, w));
  }

  for (int i = 1; i <= V; i++) {
    cin >> memo[i];
  }

  // 요구하는 지점을 경유하는 최단 거리를 구하고, 이를 최단 거리와 비교
  // 다익스트라 알고리즘(특정 정점 - 특정 정점의 최단 거리)

  // a)
  // 모든 정점에서 모든 정점의 최단 거리를 구하고 단순 합하기?
  // 1-3의 최단 거리, 3-4의 최단 거리를 합하면 1-3-4의 최단 거리인지?
  // 1-3-4의 최단 거리를 구할 때, 1-3 경로 중 무조건 4를 경유한다면?

  // b)
  // 최단 경로를 모두 구한 뒤에 노트를 모두 포함하는 최단 경로가 있는지 확인

  return 0;
}