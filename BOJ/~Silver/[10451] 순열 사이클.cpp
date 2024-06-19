#include <bits/stdc++.h>
using namespace std;

int g[1001];
int N, cnt, visited[1001];

void dfs(int i) {
  visited[i] = 1;
  if (!visited[g[i]]) dfs(g[i]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;

  while (T--) {
    cin >> N;

    for (int i = 1; i <= N; i++) cin >> g[i];
    for (int i = 1; i <= N; i++)
      if (!visited[i]) {
        dfs(i);
        cnt++;
      }
    cout << cnt << "\n";

    cnt = 0;
    memset(visited, 0, sizeof(int) * N + 1);
  }

  return 0;
}