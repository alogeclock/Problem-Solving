#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007LL

ll T, fib[51];

void init() {
  fib[0] = 1, fib[1] = 2;
  for (int i = 2; i <= 50; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  init();

  cin >> T;
  while (T--) {
    ll x;
    cin >> x;
    vector<ll> v;

    while (x) {
      for (int i = 0; i < 50; i++) {
        if (fib[i] > x) {
          x -= fib[i - 1];
          v.push_back(fib[i - 1]);
          break;
        }
      }
    }

    reverse(v.begin(), v.end());
    for (auto i : v)
      cout << i << ' ';
    cout << '\n';
  }
}

// ■ check list ■
// 1. overflow, data type, memset. ==, >=, >
// 2. first visit, % MOD