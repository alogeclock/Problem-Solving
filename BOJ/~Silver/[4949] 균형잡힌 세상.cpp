
#include <bits/stdc++.h>
using namespace std;

string ps;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N, big_ps, small_ps, chk;
  while (1) {
    stack<int> prev;

    big_ps = 0;
    small_ps = 0;

    getline(cin, ps);

    if (ps == ".") break;

    for (int i = 0; i < ps.length(); i++) {
      if (ps[i] == '(') {
        small_ps++;
        prev.push(1);
      }

      else if (ps[i] == ')') {
        small_ps--;
        if (prev.size() != 0 && prev.top() != 1) break;
        prev.pop();
      }

      else if (ps[i] == '[') {
        big_ps++;
        prev.push(2);
      }

      else if (ps[i] == ']') {
        big_ps--;
        if (prev.size() != 0 && prev.top() != 2) break;
        prev.pop();
      }

      if (big_ps < 0 || small_ps < 0) break;
    }

    if (big_ps == 0 && small_ps == 0)
      printf("yes\n");
    else
      printf("no\n");
  }

  return 0;
}