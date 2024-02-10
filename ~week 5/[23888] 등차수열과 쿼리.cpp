// idea: arithmetic sequences' gcd = gcd(a, d) (n >= 2)
// debugging: long long이 필요한 경우 변수를 모두 long long으로 맞춘다.

#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 1)

long long gcd(long long i, long long j) {
  if (j == 0) return i;
  return gcd(j, i % j);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int a, d, q;
  cin >> a >> d >> q;

  while (q--) {
    int query;
    long long l, r, left, right;
    cin >> query >> l >> r;
    left = a + (l - 1) * d, right = a + (r - 1) * d;

    if (query == 1)
      cout << (r - l + 1) * (left + right) / 2 << '\n';
    else {
      if (l == r)
        cout << left << '\n';
      else
        cout << gcd(a, d) << '\n';
    }
  }

  return 0;
}