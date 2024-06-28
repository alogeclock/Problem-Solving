#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007

ll vst[100010];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  memset(vst, 0x3f, sizeof(vst));
  ll N, K; cin >> N >> K;
  queue<pll> q; q.push({N, 0}); vst[N] = 0;

  while (q.size()) {
    auto [here, hdst] = q.front();
    q.pop();

    ll next = here + 1, ndst = hdst + 1;
    if (next <= 100000 && vst[next] > ndst) {
      vst[next] = ndst;
      q.push({next, ndst});
    }

    next = here - 1;
    if (next >= 0 && vst[next] > ndst) {
      vst[next] = ndst;
      q.push({next, ndst});
    }

    next = here * 2, ndst = hdst;
    if (next <= 100000 && vst[next] > ndst) {
      vst[next] = ndst;
      q.push({next, ndst});
    }
  }

  cout << vst[K];
  return 0;
}