#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007
int
main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  string s;
  cin >> s;

  int num = 0, sum = 0, missedSpellFactor;
  for (auto i : s) {
    int offset = i - '0';
    if (i != '*') {
      sum += (num == 0) ? offset : offset * 3;
    } else {
      missedSpellFactor = (num == 0) ? 1 : 3;
    }
    num = 1 - num; // switching binary number
  }

  for (int i = 0; i < 10; i++) {
    if ((sum + (missedSpellFactor * i)) % 10 == 0) {
      cout << i;
      break;
    }
  }
}
