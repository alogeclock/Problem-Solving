#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

list<char> s;
ll ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  char c;
  while (cin >> c) {
    bool pushed = false;
    for (list<char>::iterator iter = s.begin(); iter != s.end(); iter++) {
      if (*iter == c) {
        pushed = true;
        s.erase(iter);
        while (iter != s.end()) {
          ans++;
          iter++;
        }
      }
    }
    if (!pushed) s.push_back(c);
  }
  cout << ans;
}