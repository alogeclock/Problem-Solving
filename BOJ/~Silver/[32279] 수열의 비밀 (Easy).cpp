#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007LL

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll N; cin >> N;
  ll p, q, r, s; cin >> p >> q >> r >> s;
  
  vector<ll> v;
  ll x; cin >> x;  v.push_back(x);

  for (int i = 2; i <= N; i++) {
    if (i % 2 == 0) x = p * v[i/2 - 1] + q;
    if (i % 2) x = r * v[i/2 - 1] + s;
    v.push_back(x);
  }
  
  ll ans = 0;
  for (auto i : v) ans += i;
  cout << ans;
}

// ■ check list ■
// 1. overflow, data type, memset. ==, >=, >
// 2. first visit, % MOD