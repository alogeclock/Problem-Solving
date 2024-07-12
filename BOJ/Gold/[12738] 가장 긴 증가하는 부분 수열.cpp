// idea: lis

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

ll lis[1000100];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  memset(lis, 0x3f, sizeof(lis));
  lis[0] = -LINF;

  ll N; cin >> N;
  for (int i = 0; i < N; i++) {
    ll x; cin >> x;
    auto idx = lower_bound(lis, lis + N + 5, x) - lis; // F-T 우측
    lis[idx] = x; 
  }

  auto idx = lower_bound(lis, lis + N + 5, LINF) - lis - 1; // F-T 좌측
  cout << idx << '\n';
}