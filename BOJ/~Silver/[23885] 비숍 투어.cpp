#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  ll R, C; cin >> R >> C;
  ll sr, sc, er, ec; cin >> sr >> sc >> er >> ec;
  if (R == 1 || C == 1) (sr == er && sc == ec) ? cout << "YES" : cout << "NO";
  else ((sr + sc) % 2 == (er + ec) % 2) ? cout << "YES" : cout << "NO";
}
// ■ check list ■
// 1. overflow, data type, memset. ==, >=, >
// 2. first visit, % MOD