// idea: segment tree
// 1) 구간을 새로 정의해 범위를 계산하는 응용 idea 주의(히스토그램, Mountains)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007LL

ll arr[200020], tree[800080], N;
ll debug_trial = 1;

ll init(ll s, ll e, ll n) {
  if (s == e) return tree[n] = arr[s];
  ll mid = (s + e) / 2;
  return tree[n] = init(s, mid, 2 * n) + init(mid + 1, e, 2 * n + 1);
}

// 구간합 계산
ll query(ll s, ll e, ll n, ll l, ll r) {
  // cout << "query " << debug_trial++ << '\n';
  if (e < l || r < s) return 0;
  if (l <= s && e <= r) return tree[n];
  ll mid = (s + e) / 2;
  return query(s, mid, 2 * n, l, r) + query(mid + 1, e, 2 * n + 1, l, r);
}

// segtree 갱신
void update(ll s, ll e, ll n, ll idx, ll val) {
  if (idx < s || e < idx) return; 
  tree[n] += val;

  if (s == e) return;
  ll mid = (s + e) / 2;
  update(s, mid, 2 * n, idx, val), update(mid + 1, e, 2 * n + 1, idx, val);
  tree[n] = tree[2 * n] + tree[2 * n + 1];
}

// 이분 탐색
ll check(ll mid, ll val) {
  return query(0, N - 1, 1, 0, mid) >= val;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  init(0, N - 1, 1);
  
  for (int i = 0; i < N; i++) {
    ll x; cin >> x;

    // 이분 탐색으로 인덱스의 왼쪽의 구간합이 x 이상인 첫 인덱스를 탐색
    ll lo = -1, hi = N - 1;
    while (lo + 1 < hi) {
      ll mid = (lo + hi) / 2;
      check(mid, x) ? hi = mid : lo = mid;
    }
    cout << hi + 1 << ' ';
    update(0, N - 1, 1, hi, -arr[hi]);
  }
}

// ■ check list ■
// 1. overflow, data type, memset. ==, >=, >
// 2. first visit, % MOD