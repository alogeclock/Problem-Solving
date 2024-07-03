#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll T; cin >> T;

  while (T--) {
    string s, t; cin >> s >> t;
    int alphabet[26]; memset(alphabet, 0, sizeof(alphabet));

    for (auto i : s) alphabet[i - 'a']++;
    for (auto i : t) alphabet[i - 'a']--;
    
    int impossible = 0;
    for (auto i : alphabet) { impossible |= i; } // !0이 하나라도 있으면 set
    if (impossible) cout << "Impossible\n";
    else cout << "Possible\n";
  }
  
  return 0;
}