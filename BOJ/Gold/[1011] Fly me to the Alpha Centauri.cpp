#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  ll T; cin >> T;
  for (int i = 0; i < T; i++) {
    ll x, y; cin >> x >> y;
    ll dist = y - x, w = 1, flag = 0, ans = 0;
    while (dist > 0) {
      dist -= w;
      ans++;
      if (flag) flag = false, w++;
      else flag = true;
    }
    cout << ans << '\n';
  }
}