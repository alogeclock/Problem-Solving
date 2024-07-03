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
  int ax = a.first, bx = b.first, ay = a.second, by = b.second;
  if (ax == bx) return ay < by;
  return ax < bx;
}

bool Check(ll mid, ll ix, ll iy) {

  if (items[mid].first + ix == dx)
    return items[mid].first + iy > dy; 
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
  for (auto i : items) {
    ll ix = i.first, iy = i.second; // items_x, items_y
    ans = min(ans, (abs(dx - ix) + abs(dy - iy) + 2));
  }

  // 3) use 2 item
  for (int k = 0; k < 5; k++) { 
    ll stamina = (k == 0) ? 4 : 5;
    for (auto i : items) {
      ll ix = i.first - dr[k], iy = i.second - dc[k];

      // F-T 이분 탐색
      int lp = 0, rp = N, mid;
      while (lp + 1 < rp) {
        mid = (lp + rp) / 2;
        if (Check(mid, ix, iy)) rp = mid;
        else lp = mid;
      }

      ll cx = ix + items[lp].first, cy = iy + items[lp].second;
      if (cx == dx && cy == dy) ans = min(ans, stamina);
    }
  }

  cout << (ans > K ? -1 : ans);

  return 0;
}