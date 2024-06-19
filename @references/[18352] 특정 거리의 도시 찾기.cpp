// idea: 간단한 BFS, 복잡했던 디버깅 과정
// debugging 1) adj_matrix → adj_list: O(E); vector<vector<int> g(vertex);
// debugging 2) BFS의 방문 기준은 push(), not pop() (push() 동안 방문의 변화)
// debugging 3) 방문한 곳을 재방문하더라도 이동거리가 짧으면 갱신
// debugging 4) queue<pair<int, int>> 메모리 차지, 가능하면 dist 배열 따로 관리

#include <bits/stdc++.h>
using namespace std;
#define MAX_CITY_NUMBER 300001

vector<vector<int>> g(MAX_CITY_NUMBER);
int city[MAX_CITY_NUMBER];
bool visited[MAX_CITY_NUMBER];
int N, M, shortestLen, start;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M >> shortestLen >> start;

  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
  }

  queue<int> q;
  q.push(start);
  visited[start] = true;

  while (!q.empty()) {
    int curCity = q.front();
    int len = city[curCity];
    q.pop();
    if (len > shortestLen) continue;

    for (int i = 0; i < g[curCity].size(); i++) {
      int next = g[curCity][i];
      if (!visited[next] || city[next] > len + 1) {
        q.push(next);
        visited[next] = true;
        city[next] = len + 1;
      }
    }
  }

  int flag = 0;
  for (int i = 1; i <= N; i++) {
    if (city[i] == shortestLen) {
      cout << i << "\n";
      flag = 1;
    }
  }

  if (!flag) cout << "-1\n";

  return 0;
}