#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007

ll N, K;   // item number, initial stamina
ll dx, dy; // destination_x, destination_y
vector<pll> items;
const int dr[5] = {0, 1, -1, 0, 0}, dc[5] = {0, 0, 0, 1, -1};

bool compare(pll a, pll b) {
  auto [ax, ay] = a; auto [bx, by] = b;
  if (ax == bx) return ay < by;
  return ax < bx;
}

bool Check(ll mid, ll ix, ll iy) {
  if (items[mid].first + ix == dx)
    return items[mid].second + iy >= dy; 
  return items[mid].first + ix > dx ;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    ll x, y; cin >> x >> y;
    items.push_back({x, y});
  }
  cin >> dx >> dy;

  sort(items.begin(), items.end(), compare);

  ll ans = LINF;

  // 1) use 0 item
  ans = min(ans, abs(dx) + abs(dy));

  // 2) use 1 item
  for (auto [ix, iy] : items)
    ans = min(ans, (abs(dx - ix) + abs(dy - iy) + 2));

  // 3) use 2 item
  for (auto [ix, iy] : items) {
    for (int k = 0; k < 5; k++) { 
      ll stamina = (k == 0) ? 4 : 5;
      ll tx = ix + dr[k], ty = iy + dc[k];

      // F-T binary search
      int lo = 0, hi = N - 1;
      while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (Check(mid, tx, ty)) hi = mid - 1;
        else lo = mid + 1;
      }
      
      if (lo >= N) continue;
      tx += items[lo].first, ty += items[lo].second;
      if (tx == dx && ty == dy) ans = min(ans, stamina);
    }
  }

  cout << (ans > K ? -1 : ans);
}