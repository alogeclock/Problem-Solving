// idea: two pointer

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007

vector<int> g[100010];
int parent[100010], vst[100010];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  ll N; cin >> N;
  parent[1] = 0;
  for (int i = 0; i < N; i++) {
    int u, v; cin >> u >> v;
    g[v].push_back(u);
    g[u].push_back(v);
  }

  queue<int> q;

  memset(vst, INF, sizeof(vst));
  q.push(1); vst[1] = 1;

  while (q.size()) {
    int cur = q.front();
    int dst = vst[cur];
    q.pop();

    for (auto next : g[cur]) {
      int ndst = dst + 1;
      if (vst[next] < ndst) continue;
      vst[next] = ndst;
      parent[next] = cur;
      q.push(next);
    }
  }

  for (int i = 2; i <= N; i++) {
    cout << parent[i] << '\n';
  }
}