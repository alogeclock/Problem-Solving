// idea: dijkstra

#include <bits/stdc++.h>
using namespace std;
#define MAX_ROW 501
#define INF (1e9 + 1)
#define curV (i * (M + 1) + j)
#define nextV ((i + 1) * (M + 1) + j)
#define curVdown ((i + 1) * (M + 1) + (j + 1))
#define nextVdown (i * (M + 1) + (j + 1))

int N, M;

int dijkstra(const vector<vector<pair<int, int>>> &adj, int src, int des) {
  int max = INF;

  priority_queue<pair<int, int>> pq;  // {거리, 정점 번호} 기준 정렬
  vector<int> dist((N + 1) * (M + 1), INF);
  pq.push({0, src});

  while (!pq.empty()) {
    auto [hdst, here] = pq.top();  // 시작점부터 here까지 거리 = here_dst = hdst
    pq.pop();

    hdst *= -1;  // 우선순위 큐 특성(최소 힙)상 현재 거리 음수 저장, 바꿔줌
    if (hdst > dist[here])  // 재방문 무시
      continue;

    for (auto [next, ndst] : adj[here]) {  // 시작지점부터 next까지의 거리 계산
      ndst += hdst;
      if (dist[next] > ndst) {
        dist[next] = ndst;
        pq.push({-ndst, next});
      }
    }
  }
  return dist[des];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;

  vector<vector<pair<int, int>>> adj((N + 1) * (M + 1));

  string c;
  for (int i = 0; i < N; i++) {
    cin >> c;
    for (int j = 0; j < M; j++) {
      if (c[j] == '/') {
        adj[curV].push_back({curVdown, 1});
        adj[curVdown].push_back({curV, 1});
        adj[nextV].push_back({nextVdown, 0});
        adj[nextVdown].push_back({nextV, 0});
      } else {
        adj[curV].push_back({curVdown, 0});
        adj[curVdown].push_back({curV, 0});
        adj[nextV].push_back({nextVdown, 1});
        adj[nextVdown].push_back({nextV, 1});
      }
    }
  }

  int ans = dijkstra(adj, 0, (N + 1) * (M + 1) - 1);
  if (ans == INF)
    cout << "NO SOLUTION\n";
  else
    cout << ans;

  return 0;
}