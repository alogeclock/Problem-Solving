#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  ll N; cin >> N;
  
  vector<ll> juan;
  multiset<ll> boss;
  for (int i = 0; i < N; i++) {
    ll x; cin >> x; juan.push_back(x);
  }
  for (int i = 0; i < N; i++) {
    ll x; cin >> x; boss.insert(x);
  }
  
  sort(juan.begin(), juan.end()); // sort by ascending order
  ll ans = 0;
  for (auto value : juan) {
    auto it = boss.upper_bound(value);
    if (it != boss.end()) {
      boss.erase(it);
      ans++;
    }
  }

  (ans >= (N+1)/2) ? cout << "YES" : cout << "NO";
}