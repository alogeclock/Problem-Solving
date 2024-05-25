// idea: counting, prefix sum, recursion

#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

ll cnt[61]; // 2^(n-1) ~ 2^n - 1 범위에서 1의 개수, n >= 1
ll sum[61]; // 1 ~ 2^n - 1 범위에서 1의 개수
ll base[61]; // 2^n의 값

/*
1

10
11

100
101
110
111

1000
1001
1010
1011
1100
1101
1110
1111

ex) num = 13(1101)까지의 1의 개수

1) 7까지의 1의 개수 = sum[3]
2) 5까지의 1의 개수 = solve(5) = solve(num - base[3])
3) num - (2^3 - 1) = num - (base[3] - 1)

기준은 num / base[exp] == 0이 되는 지점으로 잡는다.

num = 15 → sum[15] 반환
*/

ll solve(ll num) {
  if (!num) return 0;
  int exp = 0;
  for (; exp <= 60; exp++)
    if (num / base[exp] == 0) break;

  if (!exp) return 1;
  if (num == base[exp] - 1) return sum[exp];
  return sum[exp - 1] + (num - base[exp - 1] + 1)+ solve(num - base[exp - 1]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  ll A, B; cin >> A >> B;

  cnt[1] = 1;
  base[0] = 1, base[1] = 2;
  sum[1] = 1;

  for (ll i = 2; i <= 60; i++) {
    cnt[i] = cnt[i - 1] * 2 + pow(2, i - 2);
    sum[i] = sum[i - 1] + cnt[i];
    base[i] = base[i - 1] * 2;
  }
  
  cout << solve(B) - solve (A - 1);
}