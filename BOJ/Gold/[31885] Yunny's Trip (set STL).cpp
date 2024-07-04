#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007

ll N, K;   // item number, initial stamina
ll dx, dy; // destination_x, destination_y
set<pll> items;
const int dr[5] = {0, 1, -1, 0, 0}, dc[5] = {0, 0, 0, 1, -1};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    ll x, y; cin >> x >> y;
    items.insert({x, y});
  }
  cin >> dx >> dy;

  ll ans = LINF;

  // 1) use 0 item
  ans = min(ans, abs(dx) + abs(dy));

  // 2) use 1 item
  for (auto i : items) {
    ll ix = i.first, iy = i.second; // items_x, items_y
    ans = min(ans, (abs(dx - ix) + abs(dy - iy) + 2));
  }

  // 3) use 2 item
  for (int k = 0; k < 5; k++) {
    ll stamina = (k == 0) ? 4 : 5;
    for (auto i : items) {
      ll cx = dx - (i.first + dr[k]), cy = dy - (i.second + dc[k]);
      if (items.find({cx, cy}) != items.end()) ans = min(ans, stamina);
    }
  }

  cout << (ans > K ? -1 : ans);

  return 0;
}