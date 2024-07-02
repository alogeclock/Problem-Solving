#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007

int alphabet[26];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string s, t; cin >> s >> t;
  for (auto i : s) alphabet[i - 'a']++;
  for (auto i : t) alphabet[i - 'a']--;

  int ans = 0;
  for (auto i : alphabet) {
    if (i > 0) ans += i;
    else if (i < 0) ans -= i;
  }

  cout << ans;
  
  return 0;
}