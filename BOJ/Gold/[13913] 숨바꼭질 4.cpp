// idea: bfs, graph dp

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

ll N, K, dst[200200], vst[200100];
ll dp[] = {-1, 1};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  memset(dst, 0x3f, sizeof(dst));
  cin >> N >> K;

  queue<ll> q; q.push(N), dst[N] = 0, vst[N] = N;
  vector<ll> v;
  while (q.size()) {
    ll cp = q.front();
    ll cdst = dst[cp];
    q.pop();

    if (cp == K) {
      cout << cdst << '\n';
      v.push_back(cp);
      while (vst[cp] != cp) {
        v.push_back(vst[cp]), cp = vst[cp];
      }
      break;
    }

    for (int i = 0; i < 3; i++) {
      ll np = cp, ndst = cdst + 1;
      (i == 2) ? np = 2 * cp : np = cp + dp[i];
      
      if (np < 0 || np > 200000) continue;
      if (ndst >= dst[np]) continue;

      dst[np] = ndst;
      vst[np] = cp;
      q.push(np);
    }
  }

  for (auto it = v.rbegin(); it < v.rend(); it++) cout << *it << ' ';
}