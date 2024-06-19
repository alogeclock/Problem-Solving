#include <bits/stdc++.h>
using namespace std;

int graph[1001][1001];
bool visited[1001];
int N, M;

void dfs(int u) {
  visited[u] = 1;
  for (int i = 1; i <= N; i++)
    if (!visited[i] && graph[u][i]) dfs(i);
}

int main() {
  int i, u, v, cnt = 0;
  scanf("%d %d", &N, &M);

  for (i = 0; i < M; i++) {
    scanf("%d %d", &u, &v);
    graph[u][v] = 1;
    graph[v][u] = 1;
  }

  for (i = 1; i <= N; i++) {
    if (visited[i] == 0) {
      dfs(i);
      cnt++;
    }
  }
  cout << cnt;
  return 0;
}