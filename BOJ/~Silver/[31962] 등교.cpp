#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

ll X, N;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> N >> X;
  ll ans = -1;
  for (int i = 0; i < N; i++) {
    ll s, e; cin >> s >> e;
    if (s + e <= X) ans = max(ans, s); 
  }

  cout << ans;
}