#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007

ll N, M, s, e;
ll dst[1010];
vector<pll> g[1010];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    ll u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
  }

  memset(dst, 0x3f, sizeof(dst));
  priority_queue<pll, vector<pll>, greater<pll>> pq;
  pq.push({0, s});
  dst[s] = 0;

  while (pq.size()) {
    auto [hdst, here] = pq.top();
    pq.pop();
    if (dst[here] < hdst) continue;
    for (auto [next, ndst] : g[here]) {
      ndst += hdst;
      if (dst[next] > ndst) {
        dst[next] = ndst;
        pq.push({ndst, next});
      }
    }
  }

  cout << dst[e];
}