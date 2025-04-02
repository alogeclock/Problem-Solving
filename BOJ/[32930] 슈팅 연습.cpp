#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

vector<pll> target;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  ll N, M; cin >> N >> M;
  for (int i = 0; i < N; i++) {
    ll x, y; cin >> x >> y; target.push_back({x, y});
  }

  ll ans = 0;
  ll cx = 0, cy = 0;
  for (int i = 0; i < M; i++) {
    ll max_dist = -1, max_idx = 0;

    for (int j = 0; j < target.size(); j++) {
      auto [tx, ty] = target[j];
      ll nx = (tx - cx), ny = (ty - cy);
      ll dist = nx * nx + ny * ny;
      if (max_dist < dist) {
        max_dist = dist;
        max_idx = j;
      }
    }

    cx = target[max_idx].first, cy = target[max_idx].second;
    target.erase(target.begin() + max_idx);
    ans += max_dist;

    ll x, y; cin >> x >> y; target.push_back({x, y});
  }

  cout << ans;
}