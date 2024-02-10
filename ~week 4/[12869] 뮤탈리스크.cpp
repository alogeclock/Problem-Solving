// idea: dp
// 1. 6가지 경우의 수를 모두 확인하여 재귀식을 작성한다.
// 2. 초기식: i, j, k가 모두 0일 때 초기식
// 3. 최적화: 반환한 값을 저장하고, 이미 계산한 식(!= -1)이라면 그대로 반환
// 4. 배열 형태: 선형 배열은 복잡함, 3차원 배열 사용
// 5. sizeof(dp), 배열을 그대로 sizeof() 함수에 넣어서 memset

#include <bits/stdc++.h>
using namespace std;

int hp[3];
int dp[61][61][61];

int re_dp(int i, int j, int k) {
  i = max(i, 0), j = max(j, 0), k = max(k, 0);
  if (i + j + k == 0)
    return 0;
  if (dp[i][j][k] != -1)
    return dp[i][j][k];

  int ret = 1e9;

  ret = min(ret, re_dp(i - 1, j - 9, k - 3) + 1);
  ret = min(ret, re_dp(i - 1, j - 3, k - 9) + 1);
  ret = min(ret, re_dp(i - 3, j - 9, k - 1) + 1);
  ret = min(ret, re_dp(i - 3, j - 1, k - 9) + 1);
  ret = min(ret, re_dp(i - 9, j - 1, k - 3) + 1);
  ret = min(ret, re_dp(i - 9, j - 3, k - 1) + 1);

  dp[i][j][k] = ret;
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;
  for (int i =0; i < N; i++) cin >> hp[i];
  memset(dp, -1, sizeof(dp)); // sizeof(dp)
  cout << re_dp(hp[0], hp[1], hp[2]);

  return 0;
}