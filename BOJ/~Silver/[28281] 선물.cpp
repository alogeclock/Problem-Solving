#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

ll arr[100010];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  ll N, X; cin >> N >> X;
  ll ans = LINF;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    if (i > 0) ans = min((arr[i-1] + arr[i]) * X, ans);
  }
  cout << ans;
}