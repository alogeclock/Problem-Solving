#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  ll N, K; cin >> N >> K;

  vector<ll> v; v.push_back(0);
  set<ll> s;

  int last;
  for (int i = 1; i <= N; i++) {
    ll x; cin >> x; 
    s.insert(x);
    v.push_back(x);
    if (i >= K) {
      ll val = *s.rbegin() - *s.begin();
      if (val == K - 1) {
        last = i;
        goto SUCCESS;
      }
      s.erase(s.find(v[i-K+1]));
    }
  }
  
  cout << "NO" << '\n';
  return 0;

  SUCCESS:
    cout << "YES" << '\n';
    for (int i = last - K + 1; i <= last; i++) {
      cout << v[i] << ' ';
    }
    return 0;
}