// idea: greedy

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  ll L, P, V, T = 1;
  while (cin >> L >> P >> V) {
    if (L == 0 & P == 0 & V == 0) break;
    ll ans = (V / P) * L + min(V % P, L);
    
    cout << "Case " << T++ << ": " << ans << '\n';
  }

  return 0;
}