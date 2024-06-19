// idea: backtracking

#include <bits/stdc++.h>
using namespace std;

vector<int> g[10001];
int connected[10001], visited[10001];
int N, M, MAX;
int cnt;

void dfs(int i) {
  cnt++;
  visited[i] = 1;

  for (int j = 0; j < g[i].size(); j++)
    if (!visited[g[i][j]]) dfs(g[i][j]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    g[v].push_back(u);  // backtracking
  }

  for (int i = 1; i <= N; i++) {
    cnt = 0;
    dfs(i);
    if (MAX <= cnt) MAX = connected[i] = cnt;
    memset(visited, 0, (N + 1) * sizeof(int));
  }

  for (int i = 1; i <= N; i++)
    if (MAX == connected[i]) cout << i << " ";

  return 0;
}