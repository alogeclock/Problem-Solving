#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int next, dst;
  Edge(int v, int d) : next(v), dst(d) {};

  // 오른쪽 부등호, 부등호 방향을 맞춰 주면 오름차순
  bool operator<(const Edge &e) const {
    if (this->next == e.next) return this->dst < e.dst;
    return this->next < e.next;
  }
  bool operator==(const Edge &e) const { return this->next == e.next; }
};

void inputGraph(vector<vector<Edge>> &g, int M, int W) {
  int u, v, d;
  for (int i = 0; i < M; i++) { // 도로
    cin >> u >> v >> d;
    g[u].push_back(Edge(v, d));
    g[v].push_back(Edge(u, d));
  }
  for (int i = 0; i < W; i++) { // 웜홀
    cin >> u >> v >> d;
    g[u].push_back(Edge(v, -d));
  }

  for (auto &edges : g) {
    sort(edges.begin(), edges.end());
    edges.erase(unique(edges.begin(), edges.end()), edges.end());
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int TC;
  cin >> TC;
  while (TC--) {
    int N, M, W;
    cin >> N >> M >> W;

    vector<vector<Edge>> g(N + 1);
    vector<int> dist(N + 1, 1e9);

    inputGraph(g, M, W); // 2. 그래프 입력

    bool minus_cycle = false;

    for (int start = 1; start <= N; start++) {
      if (dist[start] == 1e9)
        dist[start] = 0;
      else
        continue;

      for (int _ = 1; _ < N; _++) {
        for (int i = 1; i <= N; i++) {
          if (dist[i] == 1e9) continue;
          for (Edge v : g[i])
            dist[v.next] = min(dist[v.next], dist[i] + v.dst);
        }
      }

      for (int i = 1; i <= N; i++) {
        if (dist[i] == 1e9) continue;
        for (Edge v : g[i]) {
          if (dist[v.next] > dist[i] + v.dst) {
            minus_cycle = true; // 값이 갱신될 시 음수 사이클 존재
            break;
          }
        }
      }
    }

    if (minus_cycle)
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}