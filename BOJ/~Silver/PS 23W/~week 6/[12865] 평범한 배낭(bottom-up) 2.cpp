// idea: knapsack dp
// top-down: 초기 상태(개수 0, 무게 K), 전이 과정(고르거나, 고르지 않거나)
// bottom-up: 현재 여유공간에 대해 이미 담긴 최대 가치를 저장
// 2종류의 값이 주어진 것을 고르거나, 고르지 않는 것을 고려하는 문제
// 최댓값, 최솟값, 경우의 수 등을 담을 수 있음

#include <bits/stdc++.h>
#define MAX_NUM 1000001
#define INF (0x3f3f3f3f)
using namespace std;

int N, K;        // 물건의 개수, 가방의 허용 무게
int dp[100005];  // 처음엔 아무것도 담겨 있지 않으므로 가치 0
int values[105], weights[105];

// bottom-up dp
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> weights[i] >> values[i];

  for (int idx = 0; idx < N; idx++) {
    // j >= weights[idx]: 용량이 품목의 무게보다 작을 경우를 무시
    for (int w = K; w >= weights[idx]; w--) {
      dp[w] = max(dp[w], dp[w - weights[idx]] + values[idx]);
    }
  }

  int ans = 0;
  for (int i = 0; i <= K; i++) ans = max(ans, dp[i]);  // 가장 큰 값 출력
  cout << ans;
}