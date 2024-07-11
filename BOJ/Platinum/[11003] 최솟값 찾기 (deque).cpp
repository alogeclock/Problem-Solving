// idea: deque

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll N, L; cin >> N >> L;
  deque<pll> dq;
  for (int i = 0; i < N; i++) {
    ll cur; cin >> cur; 
    while (dq.size() && dq.front().first < max(i - L + 1, 0LL))
      dq.pop_front();
    while (dq.size() && dq.back().second >= cur) dq.pop_back();
    dq.push_back({i, cur});
    cout << dq.front().second << ' ';
  }
}