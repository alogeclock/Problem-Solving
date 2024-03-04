
#include <bits/stdc++.h>
using namespace std;
#define MAX_NODES 10001

typedef struct Edge {
  int next, weight;
} Edge;

typedef struct Result {
  int node;
  int weightSum;
} Result;

vector<vector<pair<int, int>>> g(MAX_NODES);  // 0: root, 1/2: child
bool vst[MAX_NODES];

Result bfs(int startNode) {
  queue<pair<int, int>> q;  // 현재 노드, 합계 가중치
  q.push({startNode, 0});
  vst[startNode] = 1;

  int max = 0;
  int farNode;

  while (!q.empty()) {
    int curNode = q.front().first;
    int curWeight = q.front().second;

    if (curWeight > max) {
      farNode = curNode;
      max = curWeight;
    }
    q.pop();

    for (int i = 0; i < g[curNode].size(); i++) {
      int nextNode = g[curNode][i].first;
      int nextWeight = g[curNode][i].second;
      if (!vst[nextNode]) {  // 연결관계 존재, 방문한 노드 X
        vst[nextNode] = 1;
        q.push({nextNode, curWeight + nextWeight});
      }
    }
  }

  Result res;
  res.node = farNode;
  res.weightSum = max;

  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;

  // tree 삽입
  int u, v, w;
  for (int i = 0; i < N - 1; i++) {
    cin >> u >> v >> w;
    g[v].push_back({u, w});
    g[u].push_back({v, w});
  }

  // 임의의 점에서 가장 먼 점으로 bfs()
  Result farNode = bfs(1);

  memset(vst, 0, MAX_NODES);
  // 가장 먼 점에서 다시 가장 먼 점으로 bfs()
  Result farFromFarNode = bfs(farNode.node);

  cout << farFromFarNode.weightSum << endl;

  return 0;
}