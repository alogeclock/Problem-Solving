// idea: dijkstra + dp
// debugging: 목적지에서 dp를 수행하면 목적지와 연결된 모든 경우를 확인
// 출발점에서 dp를 시작하면 출발점과 연결된 부분만 확인

// 목적지에서 시작되는 모든 합리적인 경로 찾기
// vs. 시작점-목적지 사이의 모든 합리적 경로 찾기

#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define pii pair<int, int>

vector<vector<pair<int, int>>> g(1005);
ll dst[1005];  // 도착지까지 가는 거리의 합
int path[1005];

int rdp(int here) {
  if (path[here]) return path[here];  // 방문했다면 반환
  for (auto [next, ndst] : g[here])
    if (dst[next] < dst[here]) path[here] += rdp(next);
  return path[here];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N, M;  // 정점 수, 간선 수
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w}), g[v].push_back({u, w});
  }

  // dijkstra algorithm을 이용해 최단 거리 획득
  memset(dst, 0x3f, sizeof(dst));
  priority_queue<pii, vector<pii>, greater<pii>> pq;  // 현재 거리, 현재 정점
  pq.push({0, 2}), dst[2] = 0;  // pq 특성을 활용하기 위해 거꾸로

  while (pq.size()) {
    auto [hdst, here] = pq.top();
    pq.pop();

    if (dst[here] < hdst) continue;

    for (auto [next, ndst] : g[here]) {
      ndst += hdst;
      if (dst[next] > ndst) {
        dst[next] = ndst;
        pq.push({ndst, next});
      }
    }
  }

  path[2] = 1;
  cout << rdp(1);
}
