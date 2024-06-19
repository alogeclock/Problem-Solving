// idea: knapsack dp
// top-down: 초기 상태(개수 0, 무게 K), 전이 과정(고르거나, 고르지 않거나)
// bottom-up: 현재 여유공간에 대해 이미 담긴 최대 가치를 저장
// 2종류의 값이 주어진 것을 고르거나, 고르지 않는 것을 고려하는 문제
// 최댓값, 최솟값, 경우의 수 등을 담을 수 있음

#include <bits/stdc++.h>
#define MAX_NUM 1000001
#define INF (0x3f3f3f3f)
using namespace std;

int N, K;  // 물건의 개수, 가방의 허용 무게
int dp[105][100005];
int itemVal[105], itemWeight[105];

// bottom-up dp
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> itemWeight[i] >> itemVal[i];
  memset(dp, -1, sizeof(dp));

  dp[0][K] = 0;  // 아무것도 고르지 않고, 무게가 꽉 찼을 때 0
  for (int idx = 0; idx < N; idx++) {
    int curW = itemWeight[idx], curV = itemVal[idx];
    for (int w = K; w >= 0; w--) {
      if (w - curW >= 0)  // 배낭에 물건을 담을 수 있다면
        dp[idx + 1][w - curW] = max(dp[idx + 1][w - curW], dp[idx][w] + curV);
      // 이전에 같은 무게로 물건을 담은 것과 비교해 더 큰 가치를 저장
      dp[idx + 1][w] = max(dp[idx + 1][w], dp[idx][w]);
      // 담지 않았을 경우에도 더 값이 큰 것 저장
    }
  }

  int ans = 0;
  for (int i = 0; i <= K; i++) ans = max(ans, dp[N][i]);  // 가장 큰 값 출력
  cout << ans;
}