// idea: set, vector

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  ll N; cin >> N;

  deque<ll> dq;
  set<ll> s; multiset<ll> ms;
  
  ll ans = 0;
  for (int i = 1; i <= N; i++) {
    ll x; cin >> x; 
    dq.push_back(x); 
    ms.insert(x);

    // if set doesn't have x
    if (s.find(x) == s.end()) {
      s.insert(x);
      // make sure deque only has 2 kinds of items
      while (s.size() > 2) {
        ll front = dq.front();
        dq.pop_front();
        ms.extract(front);
        if (ms.find(front) == ms.end())
          s.erase(front);
      }
    }

    ans = max(ans, (ll)dq.size());
  }

  cout << ans << '\n';
}