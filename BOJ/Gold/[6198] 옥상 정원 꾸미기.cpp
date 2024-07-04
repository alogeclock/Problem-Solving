// idea: stack

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007

ll height[80080], vst[80080];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll N; cin >> N;
  for (ll i = 0; i < N; i++) cin >> height[i];
  height[N] = LINF;
  
  stack<ll> s;
  for (ll i = 0; i <= N; i++) {
    while (s.size() && height[s.top()] <= height[i]) {
      vst[s.top()] = i - s.top() - 1;
      s.pop();
    }
    s.push(i);
  }

  ll sum = 0, temp = 0;

  for (ll i = 0; i < N; i++) { sum += vst[i]; }
  cout << sum;
}