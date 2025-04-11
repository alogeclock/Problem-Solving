#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ll N; cin >> N; /* total number of stones */

  ll ans = 0, inc = 1, flag = 0; // length of perimeter, increment, flag
  if (N <= 4) cout << 4;
  else {
    ll inc = 2, ans = 4, len = 4, flag = 1; 
    while (len < N) {
      len += inc;
      ans += 2;
      if (flag == 0) flag = 1;
      else {
        flag = 0;
        inc++;
      }
    }
    cout << ans;
  }
}