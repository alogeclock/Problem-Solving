// idea: unordered map

#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  // 문자열 삽입 nlogn, 탐색 10 * n * logn회

  ll T; cin >> T;
  while (T--) {
    ll N; cin >> N;
    vector<string> phone;
    unordered_map<string, int> m;
    for (ll i = 0; i < N; i++) {
      string s; cin >> s;
      phone.push_back(s);
      m[s] = 1;
    }

    bool flag = 0; // reset the flag
    for (string s : phone) {
      if (flag) break;
      string temp = "";
      for (char c : s) {
        temp += c;
        if (temp != s && m[temp]) flag = 1;
      }
    }

    flag ? cout << "NO\n" : cout << "YES\n";
  }
}