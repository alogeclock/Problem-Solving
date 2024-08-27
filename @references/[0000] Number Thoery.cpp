#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007LL

// 확장 유클리드 호제법의 응용: 모듈로 역원 구하기
ll modinv(ll x, ll MOD) {
  // 초기 상태: 두 식 nx = 0 (mod n), xy = 1 (mod n)로 x값을 구함
  ll a = MOD, b = 0;
  ll c = x % MOD, d = 1; // a > c, 나머지가 1인 수는 주기 n으로 돌아오므로 x % n
  while (c) {
    ll q = a / c; // q = ⌊a/c⌋로 가 양수가 되는 가장 작은 값 구함
    ll e = a - q * c, f = (b - q * d) % MOD;
    a = c, b = d;
    c = e, d = f;
  }
  if (a == 1) return b < 0 ? b + MOD : b;
  return -1; // 모듈로 역원을 구하지 못했을 경우
}

// gcd(a, b) = gcd(b, a) = gcd(a + b, b) = gcd(gcd(a, b), 0) 
ll euclid(ll a, ll b) {
  return (!b) ? a : gcd(a, a % b);
}

ll non_recursive_euclid(ll a, ll b) {
  while (b) {
    ll r = a % b;
    a = b; b = r;
  }
  return a;
}

// Repeated Square
ll pow(ll a, ll n) {
  if (!n) return 1;
  ll ret = pow(a, n / 2);
  return ret *= (n % 2) ? ret * a : ret;
}

// Fermat's Little Theorem: a^(-1) ≡ a^(p-2) (mod p) with p is prime
// repeated square을 응용하여 a^(p-2)를 구하는 코드, 나머지만 연산
ll FLT(ll x, ll n, ll MOD) {
  if (!n) return 1;
  ll ret = FLT(x, n / 2, MOD);
  ret = (ret * ret) % MOD;
  return ret = (n % 2) ? ret * x % MOD : ret;
}

// Euler's Theorem: a^((euler_pi(m)) - 1) ≡ 1 (mod m)
// euler_pi(m): m과 서로소인 m 이하 자연수의 수 → n * (1 - (1/prime_factor)) * ...

// Miller-Rabin Primality Test
// 수 n에 대해 (1, n) 내의 아무 a에 대해 a^(n-1) ≡ 1(mod n)이 아니면 n은 합성수
// a^(n-1) ≡ 1(mod n)일 때 소수일지는 모름 → int(2, 7, 61), ll 범위(첫 13개 소수)
// https://goodbyefin.tistory.com/47
ll miller_rabin(ll n, ll a) {
  if (a % n == 0) return 1; // FLT 조건: a와 n은 서로소
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