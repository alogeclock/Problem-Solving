// idea: dp + string
// Longest Common Subsequence: 최장 공통 부분 문자열

#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define PINF 1000000007

string first, second;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> first >> second;
  first = '\0' + first;  // 첫 문자열은 null로 초기화(r - 1, c - 1)
  second = '\0' + second;

  int row = first.length(), col = second.length();

  int LCS[row][col];  // Longest Common Subsequence
  memset(LCS, 0, sizeof(LCS));

  int ans = 0;
  for (int r = 1; r < row; r++) {
    for (int c = 1; c < col; c++) {
      if (first[r] == second[c]) {
        LCS[r][c] = LCS[r - 1][c - 1] + 1;  // 같을 시 값 추가
        ans = max(ans, LCS[r][c]);
      }
    }
  }

  cout << ans;
}