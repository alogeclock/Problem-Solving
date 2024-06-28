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

struct Path {
  ll vertex, dst;
  vector<ll> path;

  Path(ll v, ll d, vector<ll> p) {
    vertex = v;
    dst = d;
    path = p;
    path.push_back(v);
  }
  bool operator>(const Path &a) const { return dst > a.dst; }
  Path &operator=(const Path &a) {
    vertex = a.vertex, dst = a.dst;
    path = a.path;
    return *this;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  for (ll i = 0; i < M; i++) {
    ll u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
  }
  cin >> s >> e;

  priority_queue<Path, vector<Path>, greater<Path>> pq;
  vector<ll> initial_path;
  pq.push(Path(s, 0, initial_path));
  dst[s] = 0;
  memset(dst, 0x3f, sizeof(dst));

  while (pq.size()) {
    Path top = pq.top();
    ll here = top.vertex, hdst = top.dst;
    pq.pop();

    if (hdst > dst[here]) continue;
    if (here == e) {
      cout << top.dst << '\n'
           << top.path.size() << '\n';
      for (auto i : top.path)
        cout << i << ' ';
      return 0;
    }
    for (auto [next, ndst] : g[here]) {
      ndst += hdst;
      if (dst[next] > ndst) {
        dst[next] = ndst;
        pq.push(Path(next, ndst, top.path));
      }
    }
  }
}