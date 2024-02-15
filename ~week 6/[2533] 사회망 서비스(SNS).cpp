// idea: graph dp
// debugging: root node가 여러 개인 graph에 대한 대처
// 문제의 입력값을 편해 보인다고 쉽게 바꾸지 말기, 가능한 한 그대로 사용할 것

#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long

int dp[MAX_NUM][2];  // 0: 얼리어답터가 아닐 때, 1: 얼리어답터일 때
vector<vector<int>> g(MAX_NUM);

void dfs(int v, int parent);
int isEarlyAdaptor(int v, int parent);
int isNotEarlyAdaptor(int v, int parent);

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  memset(dp, -1, sizeof(dp));

  // tree는 어떤 노드를 잡아도 root 노드로 치환할 수 있음, 따라서 1로 잡음
  cout << min(isEarlyAdaptor(1, -1), isNotEarlyAdaptor(1, -1));
}

int isEarlyAdaptor(int v, int parent) {
  if (dp[v][1] != -1) return dp[v][1];

  dp[v][1] = 1;  // 방문 체크, 얼리어답터가 되는 비용

  // 자녀가 얼리어답터일 필요 X, 자녀 노드 중 작은 값을 취함
  for (auto child : g[v]) {
    if (child == parent) continue;
    dp[v][1] += min(isEarlyAdaptor(child, v), isNotEarlyAdaptor(child, v));
  }

  return dp[v][1];
}

int isNotEarlyAdaptor(int v, int parent) {
  if (dp[v][0] != -1) return dp[v][0];

  dp[v][0] = 0;  // 방문 체크

  // 자녀가 모두 얼리어답터여야 함
  for (auto child : g[v]) {
    if (child == parent) continue;
    dp[v][0] += isEarlyAdaptor(child, v);
  }

  return dp[v][0];
}
