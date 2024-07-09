#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

ll N, K, ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll N, K; cin >> N >> K;
  vector<ll> pv, nv; // positive_count, negative_count
  for (ll i = 0; i < N; i++) {
    ll x; cin >> x;
    (x < 0) ? nv.push_back(-x) : pv.push_back(x);
  }
  sort(pv.begin(), pv.end()); sort(nv.begin(), nv.end());
  for (ll i = pv.size() - 1; i >= 0; i -= K) ans += 2 * pv[i];
  for (ll i = nv.size() - 1; i >= 0; i -= K) ans += 2 * nv[i];
  cout << ans;
}