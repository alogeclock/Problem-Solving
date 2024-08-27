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

// N이 2가 아닌 소수라면 N보다 작은 양의 정수 a에 대해 다음 두 식을 만족
// a^d ≡ 1 (mod N), a^(d · 2^r) ≡ -1 (mod N) for some r
ll miller_rabin(ll n, ll a) {
  if (a % n == 0) return 1;
  ll d = n - 1;
  while (d % 2 == 0) {
    if (FLT(a, d, n) == n - 1) return 1;
    d /= 2;
  }
  ll temp = FLT(a, d, n);
  return temp == 1 || temp == n - 1;
}

ll miller_rabin_test(ll n) {
  ll base[13] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
  for (auto i : base)
    if (miller_rabin(n, i) != 1) return false;
  return true;
}

ll sqrt_test(ll n) {
  if (n <= 1) return 0;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll p, a;
  while (cin >> p >> a) {
    if (p == 0 && a == 0) return 0;
    (FLT(a, p, p) == a && !miller_rabin_test(p)) ? cout << "yes\n" : cout << "no\n";
  }
}

// ■ check list ■
// 1. overflow, data type, memset. ==, >=, >
// 2. first visit, % MOD