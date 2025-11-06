// [20303] 할로윈의 양아치.cpp
// idea: dfs + knapsack

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>

ll candy[30030], vst[30030], cnt[30030];
ll dp[30030][3030];
vector<ll> g[30030];

ll dfs(ll u) {
  vst[u] = 1, cnt[u] = 1;
  ll ans = candy[u];

  for (auto v : g[u]) {
    if (vst[v] == 0) {
      ans += dfs(v);
      cnt[u] += cnt[v];
    }
  }

  return ans;
}

int main() {
  ll N, M, K; cin >> N >> M >> K;

  for (int i = 0; i < N; i++)
    cin >> candy[i+1];
  
  for (int i = 0; i < M; i++) {
    ll u, v; cin >> u >> v;
    g[u].push_back(v); g[v].push_back(u);
  }

  vector<pll> candy_group;

  for (int i = 0; i < N; i++) {
    if (vst[i+1] == 0) {
      ll candy_cnt = dfs(i+1);
      ll child_cnt = cnt[i+1];
      candy_group.push_back({candy_cnt, child_cnt});
    }
  }

  for (int i = 0; i < candy_group.size(); i++) {
    for (int j = 0; j < K; j++) {
      dp[i+1][j] = dp[i][j];
      ll candy_cnt = candy_group[i].first;
      ll child_cnt = candy_group[i].second;
      if (j - child_cnt >= 0)
        dp[i+1][j] = max(dp[i][j], candy_cnt + dp[i][j - child_cnt]);
    }
  }

  cout << dp[candy_group.size()][K-1] << '\n';
}
