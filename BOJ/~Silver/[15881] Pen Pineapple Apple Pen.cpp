#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ll N; cin >> N; /* total number of items */
  string s; cin >> s;

  ll mode = 0, ans = 0;
  for (auto i : s) {
    if (mode == 0 && i == 'p') mode++;
    else if (mode == 1) {
      if (i == 'P') mode++;
      else if (i == 'p') mode = 1;
      else mode = 0;
    }
    else if (mode == 2) { 
      if (i == 'A') mode++;
      else if (i == 'p') mode = 1;
      else mode = 0;
    }
    else if (mode == 3 && i == 'p') {
      ans++;
      mode = 0;
    }
    else
      mode = 0;
  }

  cout << ans;
}
