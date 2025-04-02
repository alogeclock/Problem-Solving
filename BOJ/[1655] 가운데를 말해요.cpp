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
  priority_queue<ll, vector<ll>, greater<ll>> large; // 작은 원소부터 출력
  priority_queue<ll, vector<ll>, less<ll>> small;    // 큰 원소부터 출력
  
  for (int i = 0; i < N; i++) {
    ll x; cin >> x; 
    
    // initial input
    if (i == 0) {
      small.push(x);
      cout << x << '\n';
      continue;
    }

    // push
    small.top() <= x ? large.push(x) : small.push(x);

    if (small.size() >= large.size()) {
      if (small.size() > large.size() + 1) {
        x = small.top();
        small.pop();
        large.push(x);
      }
       cout << small.top() << '\n';
    }
    else if (small.size() < large.size()) { 
      if (large.size() > small.size() + 1) {
        x = large.top();
        large.pop();
        small.push(x);
      }
      cout << large.top() << '\n';
    }
  }  
}