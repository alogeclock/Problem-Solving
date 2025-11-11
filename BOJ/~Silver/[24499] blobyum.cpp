#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  ll N; cin >> N;
  for (ll r = 2; r <= 1e6; r++) {
    ll base = r * r * r;
    ll n = 3;
    while (n <= 40) {
      if (N * (r - 1) % (base - 1) == 0) {
        cout << n << '\n';
        base = N * (r - 1) / (base - 1);
        for (int i = 0; i < n; i++) {
          cout << base << ' ';
          base *= r;
        }
        cout << '\n';
        return 0;
      }

      if (base > 1e12)
        break;

      base *= r;
      n++;
    }
  }
  
  cout << -1 << '\n';
}