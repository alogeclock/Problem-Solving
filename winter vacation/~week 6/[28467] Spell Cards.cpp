// idea: range dp
// s~m 카드를 합치면서 소모한 마나 + m+1 ~ e 카드를 합치면서 소모한 마나
// + s~m 카드 중 최대값 + m+1~e 카드 중 최대값

// debugging: INF 최대값을 0x3f3f3f3f로 뒀다가 망했다.
// 최대값이 어디까지 증가할 수 있는지 생각했다면 이런 문제가 없었을 것

#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 1)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long

ll dp[405][405];
ll card[405][405];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> card[i][i];
    dp[i][i] = 0;
  }

  for (int i = 1; i <= N; i++)
    for (int j = i + 1; j <= N; j++)
      card[i][j] = max(card[i][j - 1], card[j][j]);

  for (int len = 1; len < N; len++) {
    for (int i = 1; i <= N - len; i++) {
      int s = i, e = i + len;
      dp[s][e] = LINF;
      for (int m = i; m < e; m++) {
        ll mana = card[s][m] + card[m + 1][e];
        dp[s][e] = min(dp[s][e], dp[s][m] + dp[m + 1][e] + mana);
      }
    }
  }

  cout << dp[1][N];

  return 0;
}