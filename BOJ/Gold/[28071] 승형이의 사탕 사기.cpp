// idea: bfs

#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 1)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long

int candyBox[305];
bool dp[90005];  // 최대 상자, 가져갈 수 있는 사탕 개수

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N, M, K;  // 사탕 상자의 종류, 최대 상자, 동생의 수
  cin >> N >> M >> K;

  for (int i = 0; i < N; i++) cin >> candyBox[i];

  queue<pair<int, int>> q;
  q.push({0, 0});  // 가진 사탕 수 0개, 고른 상자 수 0개

  while (q.size()) {
    int curC = q.front().first;   // current candy
    int curB = q.front().second;  // current boxes
    q.pop();

    if (dp[curC] || curB > M) continue;
    dp[curC] = true;

    for (int i = 0; i < N; i++) {
      int next = curC + candyBox[i];
      if (dp[next] || curB == M) continue;
      q.push({next, curB + 1});
    }
  }

  int maxInt = 0;
  for (int i = 0; i < 90005; i++)
    if (dp[i] && i % K == 0) maxInt = max(maxInt, i);

  cout << maxInt;
}