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

  double x, y;
  while (cin >> x >> y) {
    if (!x && !y) break;
    cout << 90 - round((atan2(x, y) * (180.0 / 3.141592))) << '\n';
  }
}