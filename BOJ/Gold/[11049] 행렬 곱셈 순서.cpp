// idea: range dp

/*
ex) 행렬이 (3, 2), (2, 5), (5, 7), (7, 2)로 4개 존재할 때
len = 1, 2, 3일 때 각각 계산,
i는 len(1) → (1, 2, 3), len(2) → (1, 2), len(3) → (1)이 성립

(len, i) | (s, e)
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
(1, 1)   | (1, 2)
(1, 2)   | (2, 3)
(1, 3)   | (3, 4)

(2, 1)   | (1, 3)
(2, 2)   | (2, 4)

(3, 1)   | (1, 4)

위처럼 계산되며,
dp[1][2]는 이 때 m = 1만 성립하므로
dp[1][2] = min(INF, dp[1][1] + dp[2][2] + 3*2*5)가 성립된다.

dp[2][3]은 어떨까? dp[2][3] 역시 m = 2만 성립하므로
dp[2][3] = min(INF, dp[2][2] + dp[3][3] + 2*5*7)이 성립한다.

len이 2이고, i가 1인 상황이라면 m은 1, 2가 성립한다. 따라서
dp[1][3]은 다음 두 값의 최솟값이 된다.

dp[1][1] + dp[2][3] + R[0] * R[1] * R[3]
dp[1][2] + dp[3][3] + R[0] * R[2] * R[3]

따라서 반복문을 돌면서 두 값을 모두 구한 뒤 서로를 비교하게 된다.
이 때, dp[2][3]과 dp[1][2] 등을 이미 구했으므로 계산이 절약된다.

이러한 과정을 반복하면, 결과적으로 dp[1][4]를 구하면서
제시된 행렬에 대한 계산 회수의 최소값을 구할 수 있게 된다.
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 1)
#define INF 0x3f3f3f3f
#define LI long long

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  LI N, R[505], dp[505][505];
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> R[i] >> R[i + 1];  // 행렬의 개수가 500개 존재할 때, 행 값 나열
  }

  // dp의 idx들은 즉 i번쨰 행렬이라고 고려하면 됨
  // ex) dp[s][e] → s번째 행렬부터 e번째 행렬까지의 곱셈 계산회수의 최솟값
  for (int i = 1; i <= N; i++) dp[i][i] = 0;  // 부분문제의 길이가 0일 때

  for (int len = 1; len < N; len++) {  // len: 부분문제의 크기를 조절하는 변수
    for (int i = 1; i <= N - len; i++) {  // i: 구간 범위의 시작 지점
      int s = i, e = len + i;  // 시작점(s)부터 끝점(e)까지의 구간
      dp[s][e] = INF;
      for (int m = s; m < e; m++) {  // m: (s, e)를 m 기준 두 부분으로 나눔
        dp[s][e] =
            min(dp[s][e], dp[s][m] + dp[m + 1][e] + R[s - 1] * R[m] * R[e]);
      }
    }
  }

  cout << dp[1][N];

  return 0;
}