#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  string s; cin >> s;
  map<string, ll> m = { {"1()", 1}, {"1)(", 1}, {")1(", 2}, 
                        {"(1)", 0}, {"()1", 1}, {")(1", 1} };
  cout << m[s];
}