// idea: dfs + 3 visited value(-1, 0, 1)
// 1에서 도달 가능하며 N번 정점을 포함하지 않는 사이클이 존재하는지 판단

#include <bits/stdc++.h>
using namespace std;

int n;
int graph[101][101];
int visited[101];  // -1: 탐색 종료, 0: 미방문, 1: 탐색 중 방문
bool flag;

void dfs(int v) {
  visited[v] = 1;

  for (int i = 1; i < n; i++) {
    if (graph[v][i] == 1) {
      if (visited[i] == 1) {
        flag = true;
        return;
      } else if (visited[i] == 0)
        dfs(i);
    }
  }

  visited[v] = -1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int x, y;
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> x;
    for (int j = 0; j < x; j++) {
      cin >> y;
      graph[i][y] = 1;
    }
  }

  dfs(1);

  if (flag)
    printf("CYCLE\n");
  else
    printf("NO CYCLE\n");
}
