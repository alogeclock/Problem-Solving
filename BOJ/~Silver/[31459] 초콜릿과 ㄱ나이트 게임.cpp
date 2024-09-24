// idea: 문제에서 나온 그대로 구현

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007LL

ll T, m[1010][1010];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> T;
  while (T--) {
    memset(m, 0, sizeof(m));

    ll R, C, dr, dc;
    cin >> C >> R >> dc >> dr;
    
    ll ans = 0;
    for (int cr = 0; cr < R; cr++) {
      for (int cc = 0; cc < C; cc++) {
        ll nr = cr + dr, nc = cc + dc;
        if (m[cr][cc]) continue;
        if (nr >= R || nc >= C || !m[nr][nc]) {
          ans++;
          m[cr][cc] = 1, m[nr][nc] = 1;
        }
      }
    }

    cout << ans << '\n';
  }
}

// ■ check list ■
// 1. overflow, data type, memset. ==, >=, >
// 2. first visit, % MOD