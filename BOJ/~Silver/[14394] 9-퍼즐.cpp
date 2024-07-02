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

  string s, t;
  while (cin >> s >> t) {
    int RGBY[4] = {0, 0, 0, 0};
    for (auto i : s) {
      if (i == 'R') RGBY[0]++;
      else if (i == 'G') RGBY[1]++;
      else if (i == 'B') RGBY[2]++;
      else if (i == 'Y') RGBY[3]++;
    }

    for (auto i : t) {
      if (i == 'R') RGBY[0]--;
      else if (i == 'G') RGBY[1]--;
      else if (i == 'B') RGBY[2]--;
      else if (i == 'Y') RGBY[3]--;
    }

    int ans = 0;
    for (auto i : RGBY)
      if (i < 0) ans -= i;
    cout << ans;
  }
}