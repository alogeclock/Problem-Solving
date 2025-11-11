#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

ll indegree[1010], vst[1010];
vector<ll> g[1010];
ll cycle_flag;

void dfs(ll cur) {
  vst[cur] = 1;
  for (auto next : g[cur]) {
    if (vst[next] == 0) dfs(next);
    if (vst[next] == 1) cycle_flag++; 
  }
  vst[cur] = 2;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  ll N, M; cin >> N >> M;

  for (int i = 0; i < M; i++) {
    ll K; cin >> K;
    ll cur; cin >> cur;
    for (int j = 1; j < K; j++) {
      ll next; cin >> next;
      g[next].push_back(cur);
      indegree[cur]++;
      cur = next;
    }
  }

  for (int i = 1; i <= N; i++) {
    if (vst[i] == 0) dfs(i);
  }

  if (cycle_flag) {
    cout << 0;
    return 0;
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
    cout << result[i] << '\n';
}#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

ll indegree[1010], vst[1010];
vector<ll> g[1010];
ll cycle_flag;

void dfs(ll cur) {
  vst[cur] = 1;
  for (auto next : g[cur]) {
    if (vst[next] == 0) dfs(next);
    if (vst[next] == 1) cycle_flag++; 
  }
  vst[cur] = 2;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  ll N, M; cin >> N >> M;

  for (int i = 0; i < M; i++) {
    ll K; cin >> K;
    ll cur; cin >> cur;
    for (int j = 1; j < K; j++) {
      ll next; cin >> next;
      g[next].push_back(cur);
      indegree[cur]++;
      cur = next;
    }
  }

  for (int i = 1; i <= N; i++) {
    if (vst[i] == 0) dfs(i);
  }

  if (cycle_flag) {
    cout << 0;
    return 0;
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

  for (int i = result.size() - 1; i >= 0; i--) {
    cout << result[i] << '\n';
  }
}