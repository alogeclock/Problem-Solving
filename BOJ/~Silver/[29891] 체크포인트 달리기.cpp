#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

ll neg_arr[200200], arr[200200];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll N, K; cin >> N >> K;
  ll pcnt = 0, ncnt = 0; // positive_count, negative_count

  for (ll i = 0; i < N; i++) {
    ll input; cin >> input;
    if (input < 0) neg_arr[ncnt++] = -input; // 양수로 저장
    else arr[pcnt++] = input;
  }

  sort(arr, arr + pcnt); // 오름차순 정렬
  sort(neg_arr, neg_arr + ncnt);
  
  ll ans = 0;

  for (ll i = pcnt; i >= 0; i -= K) {
    ans += 2 * arr[i];
  }
  for (ll i = ncnt; i >= 0; i -= K) {
    ans += 2 * neg_arr[i];
  }
  cout << ans;
}