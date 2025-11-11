#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

ll moves[101], vst[101];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  memset(vst, 0x3f, sizeof(vst));

  ll N, M; cin >> N >> M;
  for (int i = 1; i <= N + M; i++) {
    ll u, v; cin >> u >> v;
    moves[u] = v;
  }

  queue<ll> q;
  q.push(1);
  vst[1] = 0;

  while (q.size()) {
    ll cur = q.front();
    ll cdst = vst[cur];
    q.pop();

    for (int i = 1; i <= 6; i++) {
      ll next = cur + i;
      ll ndst = cdst + 1;

      while (moves[next] > 0)
        next = moves[next];      

      if (next <= 100 && vst[next] > ndst) {
        if (next == 100) {
          cout << ndst;
          goto end;
        }
        vst[next] = ndst;
        q.push(next);
      }
    }
  }

  end:
  return 0;
}