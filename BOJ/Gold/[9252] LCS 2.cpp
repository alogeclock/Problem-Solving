#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

int dp[1010][1010]; // 0번째 열, 행은 dp 계산의 편의를 위해 0 초기화

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string s, t; cin >> s >> t;
    for (int i = 1; i <= s.size(); i++) {
        for (int j = 1; j <= t.size(); j++) {
            if (s[i-1] == t[j-1]) // 문자열은 -1
                dp[i][j] = dp[i-1][j-1] + 1;
            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    string lcs;
    int i = s.size(), j = t.size();
    while (j > 0 && i > 0) {
        if (dp[i][j] != dp[i][j-1]) {
          if (dp[i][j] != dp[i - 1][j])
            lcs = s[i - 1] + lcs;
          i--;
        }
        else
            j--;
    }
    cout << dp[s.size()][t.size()];
    
    if (lcs.size())
        cout << '\n' << lcs << '\n';
}