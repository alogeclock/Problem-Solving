// idea: matrix with BFS

#include <bits/stdc++.h>
using namespace std;

int graph[101][101];
int visited[101];
int vertex, edge;
int virus;

void bfs() {
  queue<int> q;
  q.push(1);
  visited[1] = 1;

  while (!q.empty()) {
    int src = q.front();
    q.pop();

    for (int i = 1; i <= vertex; i++) {
      if (visited[i] == 0 && graph[src][i]) {
        q.push(i);
        visited[i] = 1;
        virus++;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> vertex >> edge;

  int w, v;
  for (int i = 0; i < edge; i++) {
    cin >> w >> v;
    graph[w][v] = 1;
    graph[v][w] = 1;
  }

  bfs();

  cout << virus << endl;

  return 0;
}