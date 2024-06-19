// idea: modular inverse element, FLT,

#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007

long long FLT(long long R, long long exp) {
  if (exp == 0) return 1;  // base condition
  long long ret = FLT(R, exp / 2) % INF;
  ret = (ret * ret) % INF;
  if (exp % 2) ret = ret * R % INF;
  return ret;
}

long long factorial(long long n) {
  long long ans = 1;
  for (int i = 2; i <= n; i++) ans = ans * i % INF;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  long long N, R;
  cin >> N >> R;

  R = min(R, N - R);

  R = factorial(N - R) * factorial(R) % INF;  // 순서 중요
  N = factorial(N);

  cout << N * FLT(R, INF - 2) % INF << '\n';

  return 0;
}