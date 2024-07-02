#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007

ll arr[100100];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll N; cin >> N;
  for (ll i = 0; i < N; i++) cin >> arr[i];
  ll X; cin >> X;

  // 정렬
  ll cnt = 0;
  sort(arr, arr + N);

  // 투 포인터
  ll lp = 0, rp = N - 1;
  while (lp < rp) {
    if (arr[lp] + arr[rp] > X) rp--;
    else if (arr[lp] + arr[rp] < X) lp++;
    else cnt++, lp++;
  }

  cout << cnt;

  return 0;
}