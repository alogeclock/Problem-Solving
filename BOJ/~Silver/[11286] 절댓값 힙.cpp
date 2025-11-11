#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  ll N; cin >> N;

  priority_queue<pll, vector<pll>, greater<pll>> pq;
  for (int i = 0; i < N; i++) {
    ll x; cin >> x; 
    if (x == 0) {
      if (pq.size()) {
        cout << pq.top().second << '\n';
        pq.pop();
      }
      else
        cout << "0\n";
    }
    else {
      pq.push({abs(x), x});
    }
  }
}