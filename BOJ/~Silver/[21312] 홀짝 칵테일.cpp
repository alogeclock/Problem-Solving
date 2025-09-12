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

  ll odd = 0, even = 0;
  for (int i = 0; i < 3; i++) {
    ll x;
    cin >> x;
    if (x % 2 == 0) {
      if (!even)
        even = 1;
      even *= x;
    } else {
      if (!odd)
        odd = 1;
      odd *= x;
    }
  }

  if (!odd)
    cout << even;
  else
    cout << odd;
}