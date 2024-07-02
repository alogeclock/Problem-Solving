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

  ll friend_right; cin >> friend_right;
  string a, b; cin >> a >> b;
  ll friend_wrong = b.size() - friend_right; // 친구가 틀린 개수
  ll ans = 0;

  for (int i = 0; i < a.size(); i++) {
    if (a[i] != b[i] && friend_wrong) friend_wrong--, ans++;
    if (a[i] == b[i] && friend_right) friend_right--, ans++;
  }

  cout << ans;
}