// idea: combination, modular inverse(FLT), time complexity

// (aCr · bCr)을 r = 1부터 r = b까지 더하는 과정을 어떻게 절약할 것인가?
// idea: Vandermonde's identity(조합의 곱의 합을 구하는 항등식)
// 형태를 잘 살펴보다 보면, 둘을 더한 것에서 작은 쪽만큼 고르는 것과 똑같단 것을 알게 됨

// idea: 매번 곱하고 역원을 찾는 대신 역원을 한꺼번에 계산
// idea: 팩토리얼 값을 미리 저장

#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007

long long fac[600001];

long long FLT(long long R, long long exp) {
  if (exp == 0) return 1;  // base condition
  long long ret = FLT(R, exp / 2) % INF;
  return (exp % 2) ? (ret * ret % INF) * R % INF : ret * ret % INF;
}

long long findC(long long N, long long R) {
  R = fac[N - R] * fac[R] % INF;  // 순서 중요
  N = fac[N];
  return N * FLT(R, INF - 2) % INF;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;

  fac[1] = 1;
  for (int i = 2; i <= 600000; i++) {
    fac[i] = i * fac[i - 1] % INF;
  }

  long long ans = 1;
  for (int i = 0; i < N; i++) {
    long long a, b;
    cin >> a >> b;
    ans = ans * (findC(a + b, min(a, b)) - 1) % INF;
  }

  cout << ans << '\n';

  return 0;
}