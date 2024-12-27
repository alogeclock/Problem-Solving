#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007LL

ll N, M;
vector<pll> v1, v2; // v1: 입장 및 퇴장 시작, v2: 주문 시각 및 가격

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    ll s, e; cin >> s >> e;
    v1.push_back({s, e});
  }

  ll ans = 0;
  for (int i = 0; i < M; i++) {
    ll t, p; cin >> t >> p;
    ans += p;
    v2.push_back({t, p});
  }
  
  cout << fixed;
  cout.precision(5);
  cout << ans / (long double)N;
}

// [check list]
// 1. overflow, data type, memset. ==, >=, >
// 2. first visit, % MOD