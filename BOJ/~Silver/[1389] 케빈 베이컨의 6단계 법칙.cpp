// idea: bfs, floyd-warshall
// debugging: 제발, 초기화 + 자료형 + 반복문 + 괄호 + 메모리 + 시간복잡도 생각 좀 하자.

#include <bits/stdc++.h>
using namespace std;

bool g[101][101], visited[101];
int temp_kevin[101], kevin_bacon[101];
int N, M, least = 100000000;
int idx;

void bfs(int i, int kb) {
  queue<pair<int, int>> q;
  q.push({i, kb});
  visited[i] = true;

  while (!q.empty()) {
    int src = q.front().first;
    int kevin = q.front().second;
    q.pop();
    for (int j = 1; j <= N; j++) {
      if (!visited[j] && g[src][j]) {
        q.push({j, kevin + 1});
        if (!temp_kevin[j] || temp_kevin[j] > kevin + 1)
          temp_kevin[j] = kevin + 1;
        visited[j] = true;
      }
    }
  }

  int sum = 0;
  for (int j = 1; j <= N; j++) sum += temp_kevin[j];
  if (sum < least) {
    least = sum;
    idx = i;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    g[u][v] = g[v][u] = true;
  }

  for (int i = 1; i <= N; i++) {
    bfs(i, 0);
    memset(visited, 0, 101 * sizeof(bool));
    memset(temp_kevin, 0, 101 * sizeof(int));
  }

  cout << idx << "\n";

  return 0;
}