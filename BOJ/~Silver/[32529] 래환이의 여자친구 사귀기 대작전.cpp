#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007LL

ll N, ans, anger;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    ll x; cin >> x; anger += x ? 1 : -1;
    ans += anger;
  }

  cout << ans;
}

// [check list]
// 1. overflow, data type, memset. ==, >=, >
// 2. first visit, % MOD