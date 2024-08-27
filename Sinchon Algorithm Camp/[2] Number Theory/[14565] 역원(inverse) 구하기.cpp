#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007LL

ll modinv(ll x, ll n) {
  ll a = n, b = 0, c = x % n, d = 1;
  while (c) {
    ll q = a / c, e = a - q * c, f = (b - q * d) % n;
    a = c, b = d;
    c = e, d = f;
  }
  if (a == 1) return b < 0 ? b + n : b;
  return -1;
}

// Repeated Square
ll pow(ll a, ll n) {
  if (!n) return 1;
  ll ret = pow(a, n / 2);
  return ret *= (n % 2) ? ret * a : ret;
}

// Fermat's Little Theorem: a^(-1) ≡ a^(p-2) (mod p) with p is prime
// repeated square을 응용하여 a^(p-2)를 구하는 코드, 나머지만 연산
ll FLT(ll a, ll n, ll MOD) {
  if (!n) return 1;
  ll ret = FLT(a, n / 2, MOD);
  ret = (ret * ret) % MOD;
  return ret = (n % 2) ? ret * a % MOD : ret;
}

// Euler's Theorem: a^((euler_pi(m)) - 1) ≡ 1 (mod m)
// euler_pi(m): m과 서로소인 m 이하 자연수의 수 → n * (1 - (1/prime_factor)) * ...

// Miller-Rabin Primality Test
// 수 n에 대해 (1, n) 내의 아무 a에 대해 a^(n-1) ≡ 1(mod n)이 아니면 n은 합성수
// a^(n-1) ≡ 1(mod n)일 때 소수일지는 모름 → int(2, 7, 61), ll 범위(첫 13개 소수)
ll MRT(ll n) {
  bool ret = true;
  ll base[13] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
  for (auto i : base) {
    if (i == n) return 1;
    ret &= FLT(i, n - 1, n) == 1;
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll N, A; cin >> N >> A;
  cout << N - A << ' ' << modinv(A, N);
}

// ■ check list ■
// 1. overflow, data type, memset. ==, >=, >
// 2. first visit, % MOD