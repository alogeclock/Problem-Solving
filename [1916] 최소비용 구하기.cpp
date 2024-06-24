#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007

ll N, M, s, e;
ll dst[1001];
vector<pll> g(1010);

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    ll u, v, w; cin >> u >> v >> w;
    g[u].push_back(make_pair(v, w));
    g[v].push_back(make_pair(u, w));
  }
  cin >> s >> e;

  priority_queue<pll, vector<pll>, greater<pll>> pq;
  pq.push(make_pair(0, s));
  dst[s] = 0;

  while (pq.size()) {
    ll hdst = pq.top().first, here = pq.top().second;
    pq.pop();
    if (hdst > dst[here]) continue;
    for (int i = 0; i < g[here].size(); i++) {
      ll ndst = g[here][i].first + hdst, next = g[here][i].second;
      if (dst[next] > ndst) {
        dst[next] = ndst;
        pq.push(make_pair(next, ndst));
      }
    }
  }
  
  cout << dst[e];
}