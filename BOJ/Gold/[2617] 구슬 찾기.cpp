// idea: bfs
// auto의 효과적인 활용법(일반적인 iter문보다 간단)
// 매 노드마다 vst 배열을 선언하고, 무겁거나 가벼운 구슬의 개수 파악

#include <bits/stdc++.h>
using namespace std;

int N, M;

int bfs(vector<vector<int>> g, int i) {
  int vst[100] = {0};
  queue<int> q;
  vst[i] = 1;

  q.push(i);

  int cnt = 0;
  while (q.size()) {
    int cur = q.front();
    q.pop();
    // for (auto iter = g[cur].begin(); iter != g[cur].end(); iter++)
    for (auto iter : g[cur]) {
      if (vst[iter]) continue; // 재방문 방지
      vst[iter] = 1;
      cnt++;
      q.push(iter);
    }
  }

  return cnt; // 더 무겁거나, 가벼운 구슬 개수 반환
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, M;
  cin >> N >> M;

  vector<vector<int>> g(N + 1);
  vector<vector<int>> h(N + 1);

  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    g[v].push_back(u);
    h[u].push_back(v);
  }

  queue<int> q;

  int cnt = 0;
  for (int i = 1; i <= N; i++) {
    int heavy = bfs(g, i);
    int light = bfs(h, i);
    if (heavy >= (N + 1) / 2 || light >= (N + 1) / 2) cnt++;
  }

  cout << cnt << '\n';

  return 0;
}