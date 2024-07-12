// idea: dp

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>r
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fint
#define PINF 1000000007

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  ll N; cin >> N;
  priority_queue<ll> pq;
  for (int i = 0; i < N; i++) {
    ll x; cin >> x;
    if (!x) {
      if (pq.size()) {
        cout << pq.top() << '\n';
        pq.pop();
      }
      else cout << '0' << '\n';
    } 
    else pq.push(x);
  }
}