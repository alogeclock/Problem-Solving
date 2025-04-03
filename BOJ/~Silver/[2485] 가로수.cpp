#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

vector<ll> point;

ll gcd(ll i, ll j) {
  if (j == 0) return i;
  return gcd(j, i % j);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  ll N; cin >> N;
  
  for (int i = 0; i < N; i++) {
    ll x; cin >> x; point.push_back(x);
  }
  
  ll min_dst;
  for (int i = 2; i < N; i++) {
    if (i == 2) min_dst = point[i-1] - point[i-2];
    ll dst = point[i] - point[i-1];
    min_dst = gcd(dst, min_dst);
  }

  ll ans = 0;
  for (int i = 1; i < N; i++) {
    ans += ((point[i] - point[i-1]) / min_dst) - 1;
  }
  cout << ans;
}