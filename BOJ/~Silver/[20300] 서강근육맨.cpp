#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007LL


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  // 운동기구 최대 2개, 받을 수 있을 때 최대한 많이 사용, w_1 + w_2 >= M;
  // 홀수일 때는 가장 큰 것을 제하고 2등부터 꼴등과 매칭
  ll N; cin >> N;
  vector<ll> w;
  for (int i = 0; i < N; i++) {
    ll x; cin >> x;
    w.push_back(x);
  }

  sort(w.begin(), w.end());

  ll ans = -1;
  for (int s = 0, e = w.size() - 1; s <= e; s++, e--) {
    if ((s + e) % 2 == 0) ans = max(ans, w[e]), s--;
    else ans = max(ans, w[s] + w[e]);
  }

  cout << ans;
}

// ■ check list ■
// 1. overflow, data type, memset. ==, >=, >
// 2. first visit, % MOD