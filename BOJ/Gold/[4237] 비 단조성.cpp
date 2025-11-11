#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  ll T; cin >> T;
  
  while (T--) {
    ll N; cin >> N;
    vector<ll> v;

    for (int i = 0; i < N; i++) {
      ll x; cin >> x; v.push_back(x);
    }

    if (N < 2) {
      cout << N << '\n';
      continue;
    }

    if (N == 2) {
      cout << ((v[0] > v[1]) ? 2 : 1) << '\n';
      continue;
    }
  
    deque<ll> dq;
    dq.push_back(v[0]);
    ll pgrad = 0;
    for (int i = 1; i < N; i++) {
      ll cgrad = v[i] - dq.back();
      if (pgrad == 0) {
        if (cgrad < 0) {
          dq.push_back(v[i]);
          pgrad = cgrad;
        }
        if (v[i] > dq.back()) {
          dq.pop_back();
          dq.push_back(v[i]);
        }
      }
      else if (pgrad * cgrad > 0) {
        dq.pop_back();
        dq.push_back(v[i]);
        pgrad += cgrad;
      }
      else {
        dq.push_back(v[i]);
        pgrad = cgrad;
      }
    }

    cout << dq.size() << '\n';
  }
}