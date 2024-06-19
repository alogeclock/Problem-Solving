#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e7 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define PINF 1000000

ll N;
map<ll, ll> fib;

ll fibo(ll k) {
  if (fib[k]) return fib[k];

  ll ret;

  if (k % 2) {
    ll A = fibo(k / 2);
    ll B = fibo(k / 2 + 1);
    ret = ((A * A) % PINF + (B * B) % PINF) % PINF;
  } else {
    ll A = fibo(k / 2 + 1);
    ll B = fibo(k / 2 - 1);
    ret = ((A * A) % PINF - (B * B) % PINF) % PINF;
    ret = (ret < 0) ? PINF + ret : ret;  // ret이 음수일 경우 양수 출력
  }

  fib[k] = ret;
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N;

  if (!N) {
    cout << 0;
    return 0;
  }

  fib[1] = fib[2] = 1, fib[3] = 2;
  cout << fibo(N);
}