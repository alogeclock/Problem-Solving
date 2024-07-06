// idea: stack

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
  
  ll N;
  while (cin >> N) {
    if (!N) break;
    vector<ll> height;

    for (ll i = 0; i < N; i++) {
      ll value; cin >> value;
      height.push_back(value);
    }
    height.push_back(-1); // 최종적으로 모든 값을 출력하기 위한 값

    stack<ll> s;
    ll ans = -1;
    for (ll i = 0; i <= N; i++) {
      ll top = i;
      while (s.size() && height[s.top()] > height[i]) {
        ans = max(ans, (i - s.top()) * height[s.top()]);
        height[s.top()] = height[i]; // 높이값 현재 높이로 갱신
        top = min(top, s.top());
        s.pop();
      }
      s.push(top);
    }

    cout << ans << '\n';
  }
  
}