// idea: knapsack dp
// top-down, bottom-up: 현재 여유공간 대해 이미 담긴 가치, 가능한 최대 가치
// 2종류의 값이 주어진 것을 고르거나, 고르지 않는 것을 고려하는 문제
// 최댓값, 최솟값, 경우의 수 등을 담을 수 있음

// idea: knapsack dp
// top-down, bottom-up: 현재 여유공간 대해 이미 담긴 가치, 가능한 최대 가치
// 2종류의 값이 주어진 것을 고르거나, 고르지 않는 것을 고려하는 문제
// 최댓값, 최솟값, 경우의 수 등을 담을 수 있음

#include <bits/stdc++.h>
#define MAX_NUM 1000001
#define INF (0x3f3f3f3f)
using namespace std;

int N, K;  // 물건의 개수, 가방의 허용 무게
int knapsack[105][100005];
int itemVal[105], itemWeight[105];

struct Item {
  int weight, val;
};

int dp(int idx, int weight) {
  if (weight < 0) return -INF;  // 담을 용량 초과 시 -1 return
  if (idx == N) return 0;       // 물건을 전부 고를 때 0 return
  if (knapsack[idx][weight] != -1) return knapsack[idx][weight];  // 계산 ↓

  int curW = itemWeight[idx], curV = itemVal[idx];
  int ret = max(dp(idx + 1, weight - curW) + curV, dp(idx + 1, weight));

  knapsack[idx][weight] = ret;
  return ret;
}

// top-down dp
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K;
  memset(knapsack, -1, sizeof(knapsack));
  for (int i = 0; i < N; i++) cin >> itemWeight[i] >> itemVal[i];
  cout << dp(0, K);
}