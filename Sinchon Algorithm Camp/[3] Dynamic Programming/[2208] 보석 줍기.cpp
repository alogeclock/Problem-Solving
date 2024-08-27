// idea: dynamic programming, prefix sum(range sum)
// 주요 실수 포인트: 보석을 줍지 않을 경우도 고려

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007LL

ll arr[100100], sum[100100], min_value[100100];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  memset(min_value, 0x3f, sizeof(min_value));
  ll N, M; cin >> N >> M;

  ll ans = 0; // 보석을 줍지 않을 수 있음
  min_value[0] = 0;
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
    sum[i] = arr[i] + sum[i - 1];
    min_value[i] = min(sum[i], min_value[i - 1]);
    if (i >= M) ans = max(ans, sum[i] - min_value[i - M]);
  }

  cout << ans;
}

// ■ check list ■
// 1. overflow, data type, memset. ==, >=, >
// 2. first visit, % MOD