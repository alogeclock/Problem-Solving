#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007LL

int vst[1000100];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<ll> v;

  for (int i = 1; i <= 200000; i++) {
    ll a = i, b = 3 * i, c = 5 * i;
    if (vst[a] == 2 || vst[b] == 2 || vst[c] == 2) continue;

    if (!vst[a]) {
      v.push_back(a);
      vst[a] = 2, vst[b] = 1, vst[c] = 1;
    } else if (!vst[b]) {
      v.push_back(b);
      vst[a] = 1, vst[b] = 2, vst[c] = 1;
    } else {
      v.push_back(c);
      vst[a] = 1, vst[b] = 1, vst[c] = 2;
    }
  }

  sort(v.begin(), v.end());

  ll T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    ll x;
    cin >> x;
    cout << v[x - 1] << '\n';
  }
}

// ■ check list ■
// 1. overflow, data type, memset. ==, >=, >
// 2. first visit, % MOD