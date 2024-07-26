#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  ll N; cin >> N;
  // a = 남규, b = 영훈, c = 택희
  ll ans = 0;
  for (int a = 1; a <= N; a++) {
    for (int b = 1; b <= N; b++) {
      for (int c = 1; c <= N; c++) {
        if (a >= (b + 2) && (c % 2) == 0 && (a + b + c) == N) {
          cout << a << ' ' << b << ' ' << c << '\n';
          ans++;
        }
      }
    }
  }

  cout << ans;
}

// ■ check list ■
// 1. overflow, data type, memset
// 2. first visit, % MOD