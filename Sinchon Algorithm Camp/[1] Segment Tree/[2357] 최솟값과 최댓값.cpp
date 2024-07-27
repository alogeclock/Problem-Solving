// idea: segment tree(basics)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007LL

ll arr[100010], min_tree[400040], max_tree[400040];

ll max_init(ll s, ll e, ll n) {
  if (s == e) return max_tree[n] = arr[s];
  ll mid = (s + e) / 2;
  return max_tree[n] = max(max_init(s, mid, 2 * n), max_init(mid + 1, e, 2 * n + 1));
}

ll max_query(ll s, ll e, ll n, ll l, ll r) {
  if (r < s || e < l) return 0;
  if (l <= s && e <= r) return max_tree[n];
  ll mid = (s + e) / 2;
  return max(max_query(s, mid, n * 2, l, r), max_query(mid + 1, e, 2 * n + 1, l, r));
}

ll min_init(ll s, ll e, ll n) {
  if (s == e) return min_tree[n] = arr[s];
  ll mid = (s + e) / 2;
  return min_tree[n] = min(min_init(s, mid, 2 * n), min_init(mid + 1, e, 2 * n + 1));
}

ll min_query(ll s, ll e, ll n, ll l, ll r) {
  if (r < s || e < l) return LINF;
  if (l <= s && e <= r) return min_tree[n];
  ll mid = (s + e) / 2;
  return min(min_query(s, mid, n * 2, l, r), min_query(mid + 1, e, 2 * n + 1, l, r));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll N, M; cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> arr[i];
  max_init(0, N - 1, 1); min_init(0, N - 1, 1);

  for (int i = 0; i < M; i++) {
    ll a, b; cin >> a >> b;
    cout << min_query(0, N - 1, 1, a - 1, b - 1) << ' ';
    cout << max_query(0, N - 1, 1, a - 1, b - 1) << '\n';
  }
}

// ■ check list ■
// 1. overflow, data type, memset. ==, >=, >
// 2. first visit, % MOD