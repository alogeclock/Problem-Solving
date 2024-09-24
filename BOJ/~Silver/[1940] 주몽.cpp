// idea: 모든 값이 고유하고 i, M - i가 유일한 하나의 쌍

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007LL

ll N, M, ans;
vector<ll> v;
map<ll, ll> m;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    ll x; cin >> x;
    v.push_back(x);
    m[x] = 1;
  }

  for (auto i : v) {
    if (m[i]) {
      m[i]--;
      if (m[M - i]) {
        ans++;
        m[M - i]--;
      }
    } 
  }

  cout << ans;
}

// ■ check list ■
// 1. overflow, data type, memset. ==, >=, >
// 2. first visit, % MOD