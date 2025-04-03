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

  ll N; cin >> N;
  string s, t;
  for (int i = 0; i < N; i++) {
    ll x; cin >> x;
    if (x == 0) s += ' ';
    else if (x <= 26) s += 'A' + (x-1);
    else s += 'a' + (x-27);
  }
  cin.ignore();
  getline(cin, t);
  
  ll flag = 1;
  for (auto c : s) {
    auto it = t.find(c);
    if (it != string::npos) t.erase(it);
    else flag = 0;
  }

  flag ? cout << 'y' : cout << 'n';
}