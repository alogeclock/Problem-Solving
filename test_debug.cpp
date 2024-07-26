#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000009LL

bool vst[100010];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll N, M;
  while (cin >> N >> M) {
    vector<ll> v, nv;
    memset(vst, 0, sizeof(vst));
    
    for (ll i = 0; i < M; i++) {
      ll x; cin >> x; v.push_back(x);
      vst[x] = true;
    }

    ll last = 1;
    for (auto i : v) {
      for (int j = last; j <= N; j++) {
        if (j > i) { last = j; break; }
        if (!vst[j]) { vst[j] = true; nv.push_back(j); }
      }
      nv.push_back(i);
    }
    for (int i = last; i <= N; i++) if (!vst[i]) nv.push_back(i);

    for (auto i : nv) cout << i << '\n';
  }
}

// ■ check list ■
// 1. overflow, data type, memset. ==, >=, >
// 2. first visit, % MOD