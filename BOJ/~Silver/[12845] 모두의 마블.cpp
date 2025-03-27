#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007

ll lv, max_lv, sum;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll N; cin >> N;

  ll max_lv = 0;
  ll sum = 0;
  stack<ll> st;
  for (int i = 0; i < N; i++) {
    cin >> lv;
    sum += lv;
    max_lv = max(lv, max_lv);
  }
  sum += max_lv * (N - 2);

  cout << sum;
}