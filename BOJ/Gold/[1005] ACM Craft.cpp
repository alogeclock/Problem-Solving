// idea: topological sort
// 노드 사이의 거리를 누적합 + 현재 노드를 삭제했을 때의 잎새 노드를 삽입

#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T; // test case
  while (T--) {
    int N, K;
    cin >> N >> K; // num of building, num of rules
    int time[1010] = {0}, indegree[1010] = {0}, vst[1010] = {0};
    vector<vector<int>> g(N + 1);
    for (int i = 1; i <= N; i++)
      cin >> time[i];
    for (int i = 0; i < K; i++) {
      int s, e;
      cin >> s >> e;
      g[s].push_back(e);
      indegree[e]++;
    }
    int W;
    cin >> W;

    queue<int> q;
    for (int i = 1; i <= N; i++) {
      if (!indegree[i]) {
        vst[i] = time[i];
        q.push(i);
      }
    }

    while (q.size()) {
      int here = q.front();
      q.pop();

      for (auto next : g[here]) {
        indegree[next]--;
        vst[next] = max(vst[next], time[next] + vst[here]);
        if (!indegree[next]) {
          q.push(next);
        }
      }
    }
    cout << vst[W] << '\n';
  }
}