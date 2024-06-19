// idea: topological sort, unordered map, priority queue

#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

int indegree[400020];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int N; cin >> N; // relation_count
  unordered_map<int, string> mis;
  unordered_map<string, int> msi;
  vector<vector<int>> g(400020);

  int cnt = 1; // item_count
  for (int i = 0; i < N; i++) {
    string s, e;
    cin >> s >> e;
    if (!msi[s]) { msi[s] = cnt; mis[cnt++] = s; }
    if (!msi[e]) { msi[e] = cnt; mis[cnt++] = e; }
    g[msi[s]].push_back(msi[e]);
    indegree[msi[e]]++;
  }

  priority_queue<string, vector<string>, greater<string>> pq;
  vector<int> order;
  for (int i = 1; i < cnt; i++) {
    if (!indegree[i]) pq.push(mis[i]);
  }

  while (pq.size()) {
    vector<int> temp;
    while (pq.size()) {
      int top = msi[pq.top()];
      temp.push_back(top);
      order.push_back(top);
      pq.pop();
    }    
    for (int i : temp) {
      for (int next : g[i]) {
        indegree[next]--;
        if (!indegree[next]) {
          pq.push(mis[next]);
        }
      }
    }
  }

  for (int i = 1; i < cnt; i++) {
    if (indegree[i]) {
      cout << "-1";
      return 0;
    }
  }

  for (auto i : order) {
    cout << mis[i] << '\n';
  }
}