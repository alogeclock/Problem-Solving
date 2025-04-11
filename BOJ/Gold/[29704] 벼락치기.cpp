#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll date[1010], penalty[1010];
ll dp[1010][1010]; // dp[checked problems so far][elapsed days]

int main() {
  ll N, T; cin >> N >> T;

  ll total = 0;
  for (int i = 1; i <= N; i++) {
    cin >> date[i] >> penalty[i];
    total += penalty[i];
  }

  for (int p = 1; p <= N; p++) { // checked problems until now
    for (int t = 1; t <= T; t++) { // elapsed days
      if (t - date[p] >= 0)
        dp[p][t] = max(dp[p-1][t], dp[p-1][t - date[p]] + penalty[p]);
      else dp[p][t] = dp[p-1][t];
    }
  }

  cout << total - dp[N][T];
}