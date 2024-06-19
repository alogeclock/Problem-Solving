#include <bits/stdc++.h>
using namespace std;
#define MAX_NODES 20001
#define RED 1
#define BLUE -1
#define NON_VISIT 0

vector<vector<int>> g(MAX_NODES);
int vst[MAX_NODES];
bool flag = 0;

void bfs(const vector<vector<int>> &g, int cur) {
  queue<pair<int, int>> q;
  q.push({cur, RED});
  vst[cur] = RED;

  while (!q.empty()) {
    cur = q.front().first;
    int curColor = q.front().second;
    int nextColor = (-1) * curColor;
    q.pop();

    for (int i = 0; i < g[cur].size(); i++) {
      int next = g[cur][i];

      if (vst[next] == curColor) {
        flag = 1;
        return;
      }
      if (vst[next] == NON_VISIT) {
        q.push({next, nextColor});
        vst[next] = nextColor;
      } else
        continue;
    }
  }
}

void isBipartite(int V, int E) {
  vector<vector<int>> g(V + 1);

  int u, v;
  for (int i = 0; i < E; i++) {
    cin >> u >> v;
    g[v].push_back(u);
    g[u].push_back(v);
  }

  for (int i = 1; i <= V; i++)
    if (!vst[i]) bfs(g, i);

  if (flag)
    cout << "NO\n";
  else
    cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // 정점을 서로 다른 색으로 칠할 때,
  int T;
  cin >> T;

  while (T--) {
    flag = 0;  // flag가 1이면 bipartite graph
    int V, E;
    cin >> V >> E;

    memset(vst, NON_VISIT, sizeof(int) * (V + 1));
    isBipartite(V, E);
  }

  return 0;
}