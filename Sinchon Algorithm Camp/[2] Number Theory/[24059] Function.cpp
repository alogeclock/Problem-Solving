#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007LL

ll FLT(ll x, ll n, ll MOD) {
  if (!n) return 1;
  ll ret = FLT(x, n / 2, MOD);
  ret = (ret * ret) % MOD;
  return ret = (n % 2) ? (ret * x) % MOD : ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll n, m, a[3]; cin >> n;
  for (int i = 0; i <= n; i++) cin >> a[i];
  cin >> m;

  // 지수가 0이 되지 않도록 (m - 1)을 더함
  if (n == 2) cout << FLT(a[2], FLT(a[1], a[0], m - 1) + (m - 1), m);
  if (n == 1) cout << FLT(a[1], a[0], m);
  if (n == 0) cout << a[0] % m;
}

// ■ check list ■
// 1. overflow, data type, memset. ==, >=, >
// 2. first visit, % MOD