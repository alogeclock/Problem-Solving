// idea: bfs
// auto의 효과적인 활용법(일반적인 iter문보다 간단)
// 매 노드마다 vst 배열을 선언하고, 무겁거나 가벼운 구슬의 개수 파악

#include <bits/stdc++.h>
using namespace std;

int N, M;
int in[501], out[501];

void bfs(vector<vector<int>> g, int i) {
  int vst[501] = {0};
  queue<int> q;
  vst[i] = 1;

  q.push(i);

  while (q.size()) {
    int cur = q.front();
    q.pop();
    if (cur != i) {
      out[i]++;   // i보다 더 키가 큰 학생의 수
      in[cur]++;  // cur보다 더 키가 작은 학생의 수
    }
    // for (auto iter = g[cur].begin(); iter != g[cur].end(); iter++)
    for (auto iter : g[cur]) {
      if (vst[iter]) continue;  // 재방문 방지
      vst[iter] = 1;
      q.push(iter);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, M;
  cin >> N >> M;

  vector<vector<int>> g(N + 1);

  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    g[v].push_back(u);
  }

  queue<int> q;

  int cnt = 0;
  for (int i = 1; i <= N; i++) bfs(g, i);

  for (int i = 1; i <= N; i++)
    if (in[i] + out[i] == N - 1) cnt++;

  cout << cnt << '\n';

  return 0;
}