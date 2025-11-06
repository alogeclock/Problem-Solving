// idea: topological sort

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> g[32030];
ll indegree[32030];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  ll N, M; cin >> N >> M;

  for (int i = 0; i < M; i++) {
    ll u, v; cin >> u >> v;
    g[v].push_back(u);
    indegree[u]++;
  }

  queue<ll> q;
  for (int i = 1; i <= N; i++) {
    if (indegree[i] == 0)
      q.push(i);
  }

  vector<ll> result;
  while (q.size()) {
    ll cur = q.front();
    q.pop();
    result.push_back(cur);

    for (auto next : g[cur]) {
      indegree[next]--;
      if (indegree[next] == 0)
        q.push(next);
    }
  }
  
  for (int i = result.size() - 1; i >= 0; i--)
    cout << result[i] << ' ';
}
