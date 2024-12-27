#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 998244353LL

ll W, H, K, T;
vector<pll> v;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> W >> H >> K >> T;

  ll ans = 1; // 가능한 바이러스 분포
  for (int i = 0; i < K; i++) {
    ll w, h; cin >> w >> h; v.push_back({w, h});
    ll maxw, minw, maxh, minh;

    w = min(w + T, W) - max(w - T, 1LL) + 1; // 가능한 가로 범위
    h = min(h + T, H) - max(h - T, 1LL) + 1; // 가능한 세로 범위
    ans = (((w * h) % PINF) * ans) % PINF;
  }

  cout << ans;
}

// [check list]
// 1. overflow, data type, memset. ==, >=, >
// 2. first visit, % MOD