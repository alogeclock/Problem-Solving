#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  ll T; cin >> T;
  const char oper[4] = {'D', 'S', 'L', 'R'};

  while (T--) {
    ll u, v; cin >> u >> v;
    ll base = 1000;

    ll vst[10000], pre_oper[10000], pre_val[10000];
    memset(vst, 0, sizeof(vst));
    vst[u] = 1;
    pre_val[u] = -1;

    queue<ll> q;
    q.push(u);

    while (q.size()) {
      ll cur = q.front();
      q.pop();

      if (cur == v) {
        vector<char> v;
        ll prev = pre_val[cur];

        while (pre_val[cur] != -1) {
          v.push_back(oper[pre_oper[cur]]);
          cur = prev;
          prev = pre_val[cur];
        }

        for (int i = v.size() - 1; i >= 0; i--)
          cout << v[i];
        cout << '\n';

        break;
      }

      for (int i = 0; i < 4; i++) {
        ll next;

        switch (i) {
          case 0:
            next = cur * 2;
            if (next >= 10000) next %= 10000;
            break;
          case 1:
            next = cur - 1;
            if (next < 0) next += 10000;
            break;
          case 2:
            next = ((cur * 10) % 10000) + ((cur * 10) / 10000);
            break;
          case 3:
            next = (cur / 10) + ((cur % 10) * 1000);
            break;
        }

        if (!vst[next]) {
          q.push(next);
          vst[next] = 1;
          pre_val[next] = cur;
          pre_oper[next] = i;
        }
      }
    }
  }
}