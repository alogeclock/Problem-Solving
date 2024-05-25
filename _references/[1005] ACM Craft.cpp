// idea: topological sort
// 노드 사이의 거리를 누적합 + 현재 노드를 삭제했을 때의 잎새 노드를 삽입

#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define PINF 1000000007
#define pii pair<int, int>
#define pll pair<ll, ll>

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;

  while (T--) {
    int N, K, W; // vertex의 개수, edge의 갯수
    int dst[1010] = {0}, vst[1010] = {0}, indegree[1010] = {0};

    cin >> N >> K;
    vector<vector<int>> g(N + 1); // 정경로

    for (int i = 1; i <= N; i++)
      cin >> dst[i];
    for (int i = 1; i <= K; i++) {
      int s, e;
      cin >> s >> e;
      g[s].push_back(e);
      indegree[e]++;
    }
    cin >> W; // 최종 노드

    queue<int> q;
    for (int i = 1; i <= N; i++) {
      if (!indegree[i]) {
        vst[i] = dst[i];
        q.push(i);
      }
    }

    while (q.size()) {
      int here = q.front();
      q.pop();

      for (int next : g[here]) {
        int ndst = vst[here] + dst[next];
        if (ndst > vst[next]) vst[next] = ndst;
        indegree[next]--;
        if (!indegree[next]) q.push(next);
      }
    }
    cout << vst[W] << '\n';
  }
}
