#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007LL

ll ans, a, b, c, d, i, j;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll N; cin >> N;
  while (N--) {
    ll x; cin >> x;
    switch (x) {
      case 0: a++; break;
      case 1: b++; break;
      case 2: c++; break;
      case 3: d++; break;
    }
  }

  i = min(a, d), j = min(b, c);
  ans = (i + j) * 3;
  a -= i, d -= i, b -= j, c -= j;

  i = min(a, c), j = min(b, d);
  ans += (i + j) * 2;
  a -= i, c -= i, b -= j, d -= j;

  ans += (min(a, b) + min(c, d));

  cout << ans;
}

// ■ check list ■
// 1. overflow, data type, memset. ==, >=, >
// 2. first visit, % MOD