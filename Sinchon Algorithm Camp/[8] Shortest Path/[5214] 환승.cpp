#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007LL

int N, K, M;
int vst[100100];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  memset(vst, 0x3f, sizeof(vst));

  cin >> N >> K >> M;
  vector<int> g[N + M + 1];
  for (int i = 1; i <= M; i++) {
    vector<int> v;
    for (int j = 0; j < K; j++) {
      int x; cin >> x;
      v.push_back(x);
    }
    for (auto j : v) {
      g[j].push_back(N + i);
      g[N + i].push_back(j);
    }
  }

  queue<pair<int, int>> q; q.push({1, 0});
  vst[1] = 0;

  while (q.size()) {
    auto [cur, cdst] = q.front();
    q.pop();
    for (auto next : g[cur]) {
      int ndst = cdst + 1;
      for (auto dest : g[next]) {
        if (vst[dest] <= ndst) continue;
        vst[dest] = ndst;
        q.push({dest, ndst});
      }
    }
  }

  (vst[N] == LINF) ? cout << -1 : cout << vst[N] + 1;
}

// ■ check list ■
// 1. overflow, data type, memset. ==, >=, >
// 2. first visit, % MOD