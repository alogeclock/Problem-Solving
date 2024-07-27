// idea: segment tree(basics)

// 1) leaf node에서부터 값 갱신
// 2) mul() 함수에서 0을 곱하는 대신 1을 곱함
// 3) % MOD 연산 주의

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007LL
#define MAX_NUMBER 1000000

ll arr[MAX_NUMBER], tree[4 * MAX_NUMBER];

ll init(ll s, ll e, ll node) {
  if (s == e) return tree[node] = arr[s];
  ll mid = (s + e) / 2;
  return tree[node] = (init(s, mid, node * 2) * init(mid + 1, e, node * 2 + 1)) % PINF;
}

// [s, e]는 현재 읽는 범위, [l, r]은 내가 원하는 범위
ll mul(ll s, ll e, ll node, ll l, ll r) {
  if (e < l || r < s) return 1; // 0을 곱하는 대신 1을 곱해야 구간곱이 모두 0이 되지 않음
  if (l <= s && e <= r) return tree[node];
  ll mid = (s + e) / 2;
  return (mul(s, mid, node * 2, l, r) * mul(mid + 1, e, node * 2 + 1, l, r)) % PINF;
}

// 이전처럼 만날 때마다 갱신하는 대신, leaf node에서부터 역으로 값을 갱신하는 응용
void update(ll s, ll e, ll node, ll idx, ll value) {
  if (idx < s || idx > e) return;
  if (s == e) { tree[node] = value; return; }

  ll mid = (s + e) / 2;
  update(s, mid, node * 2, idx, value), update(mid + 1, e, node * 2 + 1, idx, value);
  tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % PINF;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  // M: update query, K: prefix mul query
  ll N, M, K; cin >> N >> M >> K;
  for (int i = 0; i < N; i++) cin >> arr[i];
  
  ll T = M + K;
  init(0, N - 1, 1);
  
  while (T--) {
    ll a, b, c; cin >> a >> b >> c;
    if (a == 1) update(0, N - 1, 1, b - 1, c);
    else cout << mul(0, N - 1, 1, b - 1, c - 1) << '\n';
  }
}

// ■ check list ■
// 1. overflow, data type, memset. ==, >=, >
// 2. first visit, % MOD