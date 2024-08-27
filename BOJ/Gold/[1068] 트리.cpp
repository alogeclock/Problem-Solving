#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007LL

ll tree[51], indegree[51];

bool dfs(ll i) {
  if (tree[i] == -1) return true; // leaf node
  if (tree[i] == -2) return false;
  return dfs(tree[i]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll N; cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> tree[i];
    if (tree[i] >= 0) indegree[tree[i]]++;
  }
  ll delete_node; cin >> delete_node;
  indegree[tree[delete_node]]--;
  tree[delete_node] = -2;

  ll ans = 0;
  for (int i = 0; i < N; i++) {
    if (indegree[i] == 0 && i != delete_node && dfs(i)) ans++;
  }

  cout << ans;
}

// ■ check list ■
// 1. overflow, data type, memset. ==, >=, >
// 2. first visit, % MOD