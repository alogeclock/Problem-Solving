// idea: set
// s.find(), s.count(), s.insert(), s.erase(), s.swap(), s.rbegin(), s.rend()

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

  ll N; cin >> N;
  set<string> employee;
  while (N--) {
    string s, t; cin >> s >> t;
    if (t == "enter") employee.insert(s);
    if (t == "leave") employee.erase(s);
  }

  vector<string> v;
  for (auto it = employee.begin(); it != employee.end(); it++)
    v.push_back(*it);
  sort(v.begin(), v.end(), greater<string>());

  for (auto i : v) cout << i << '\n';
}