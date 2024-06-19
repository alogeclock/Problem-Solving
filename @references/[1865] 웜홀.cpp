// idea: difference of dijkstra, bellman-ford

// dijkstra(priority_queue + BFS, 모든 vertex 방문할 때까지 최단거리 배열 갱신)
// 1. 시작 노드에 인접한 미방문 노드의 최단 거리 갱신
// 2. 인접한 미방문 노드 중 가장 가까운 노드 선택
// 3. 1·2 반복(모든 vertex 방문할 때까지; vst, dist 배열 필요)

// bellman-ford()
// 1. 시작 노드 거리 0 초기화
// 2. 모든 vertex에 연결된 edge 순회를 V-1번 실시
// 3. 모든 vertex에 연결된 edge 순회 V번째로 실시(값 갱신 시 음수 사이클 존재)

// Q1. 왜 V-1번인가? '최단 경로의 최대 길이'가 V-1번이기 떄문, 더 길 순 없음
// Q2. relaxation이 정확히 뭘까? 어떻게 돌아가고 있을까?
// 1. vertex V개를 INF로 채워 보고 최단 경로를 찾아본다.
// 2. 물론 모든 edge를 살피지만, 시작점과 무관한 간선은 갱신이 없다(INF 값)
// 3. 따라서 마치 BFS, 다익스트라를 실행하는 것처럼 동작하게 된다.

#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int next, dst;
  Edge(int v, int d) : next(v), dst(d){};

  // 오른쪽 부등호, 부등호 방향을 맞춰 주면 오름차순
  bool operator<(const Edge &e) const {
    if (this->next == e.next) return this->dst < e.dst;
    return this->next < e.next;
  }
  bool operator==(const Edge &e) const { return this->next == e.next; }
};

void inputGraph(vector<vector<Edge>> &g, int M, int W) {
  int u, v, d;
  for (int i = 0; i < M; i++) {  // 도로
    cin >> u >> v >> d;
    g[u].push_back(Edge(v, d));
    g[v].push_back(Edge(u, d));
  }
  for (int i = 0; i < W; i++) {  // 웜홀
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

    inputGraph(g, M, W);  // 2. 그래프 입력

    bool minus_cycle = false;

    for (int start = 1; start <= N; start++) {
      if (dist[start] == 1e9)
        dist[start] = 0;
      else
        continue;

      // 3. 모든 vertex에 연결된 edge 순회를 V-1번 실시
      for (int _ = 1; _ < N; _++) {
        for (int i = 1; i <= N; i++) {
          if (dist[i] == 1e9) continue;
          for (Edge v : g[i]) dist[v.next] = min(dist[v.next], dist[i] + v.dst);
        }
      }

      // 4. 모든 vertex에 연결된 edge 순회 V번째로 실시
      for (int i = 1; i <= N; i++) {
        if (dist[i] == 1e9) continue;
        for (Edge v : g[i]) {
          if (dist[v.next] > dist[i] + v.dst) {
            minus_cycle = true;  // 값이 갱신될 시 음수 사이클 존재
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