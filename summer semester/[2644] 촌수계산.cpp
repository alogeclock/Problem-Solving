#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define PINF 1000000007

vector<int> g[105];  // 부자 관계
int vst[105];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N;         // 전체 사람의 수
  int src, des;  // 촌수 관계를 계산해야 하는 둘의 번호
  int M;         // 부모 자식 간 관계의 수

  cin >> N >> src >> des >> M;

  for (int i = 0; i < M; i++) {
    int parent, child;
    cin >> parent >> child;
    g[parent].push_back(child);
    g[child].push_back(parent);
  }

  queue<pair<int, int>> q;
  q.push({src, 0});

  while (q.size()) {
    auto [cur, cdst] = q.front();
    q.pop();

    if (vst[cur]) continue;  // 이미 방문했다면 skip
    if (cur == des) {
      cout << cdst;
      return 0;
    }
    vst[cur] = 1;

    for (auto child : g[cur]) {
      if (!vst[child]) q.push({child, cdst + 1});
    }
  }

  cout << -1;
}
