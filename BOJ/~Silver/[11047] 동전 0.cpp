#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  ll N, K; cin >> N >> K;
  vector<ll> coins;
  for (int i = 0; i < N; i++) {
    ll x; cin >> x; coins.push_back(x);
  }
  reverse(coins.begin(), coins.end());

  ll ans = 0;
  for (auto c : coins) {
    ans += K / c;
    K %= c;
  }
  cout << ans;
}