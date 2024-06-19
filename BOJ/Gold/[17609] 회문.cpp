#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int T;
  cin >> T;

  while (T--) {
    int isPalindrome = 0, p;
    string s;
    cin >> s;

    for (int i = 0, j = s.length() - 1; i < j;) {  // s.length() >= 3
      if (s[i] == s[j])
        i++, j--;
      else if (!isPalindrome) {  // 아직 한 번도 틀린 적 X
        isPalindrome = 1, p = 1;
        while (s[i + p] == s[j - p + 1] && s[j - p] == s[i + p - 1]) {
          if (i + p == j - p + 1) break;
          p++;
        }
        if (s[i + p] == s[j - p + 1])
          i++;
        else if (s[j - p] == s[i + p - 1])
          j--;
        else {
          isPalindrome = 2;
          break;
        }
      } else {
        isPalindrome = 2;
        break;
      }
    }

    cout << isPalindrome << '\n';
  }

  return 0;
}