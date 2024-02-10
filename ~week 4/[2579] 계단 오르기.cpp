#include <bits/stdc++.h>
using namespace std;

int stairs[500];
int dp[500];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> stairs[i];
    dp[i] = stairs[i];
  }

  dp[2] += stairs[1];
  for (int i = 3; i <= N; i++) {
    dp[i] += max(dp[i - 3] + stairs[i - 1], dp[i - 2]);
  }

  cout << dp[N];

  return 0;
}