#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

vector<ll> parent;
vector<tuple<ll, ll, ll>> edge;

bool compare(tll &a, tll &b) {
  return get<2>(a) < get<2>(b);
}

ll find(ll x) {
  if (parent[x] == x) return x;
  return parent[x] = find(parent[x]);
}

void unite(ll u, ll v) {
  u = find(u), v = find(v);
  u < v ? parent[v] = u : parent[u] = v;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  ll V, E; cin >> V >> E;
  for (int i = 0; i <= V; i++) {
    parent.push_back(i);
  }
  for (int i = 0; i < E; i++) {
    ll u, v, w; cin >> u >> v >> w; edge.push_back({u, v, w});
  }

  sort(edge.begin(), edge.end(), compare);

  ll ans = 0;
  for (auto e : edge) {
    auto [u, v, w] = e;
    if (find(u) != find(v)) {
      unite(u, v);
      ans += w;
    }
  }

  cout << ans;
}