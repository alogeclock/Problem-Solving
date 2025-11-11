#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>

ll P[101];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  ll T; cin >> T;
  P[0] = 1, P[1] = 1, P[2] = 1;
  for (int i = 3; i < 100; i++) {
    P[i] = P[i-2] + P[i-3];
  }

  while (T--) {
    ll N; cin >> N;
    cout << P[N-1] << '\n';
  }
}