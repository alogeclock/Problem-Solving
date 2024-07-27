// idea: segment tree
// 1) 세그먼트 트리의 노드에 최솟값의 인덱스를 저장
// 2) maxArea() 함수로 최솟값의 인덱스를 찾은 뒤 왼쪽, 오른쪽에 대해 재귀 탐색
// 재귀 탐색이 가능한 이유: 영역이 최솟값 기준으로 구분되기 때문

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007LL

ll arr[100010], tree[400040], N;

ll init(ll s, ll e, ll n) {
  if (s == e) return tree[n] = s;
  ll mid = (s + e) / 2;
  ll left = init(s, mid, 2 * n), right = init(mid + 1, e, 2 * n + 1);
  (arr[left] > arr[right]) ? tree[n] = right : tree[n] = left;

  return tree[n];
}

// 최소값이 위치한 인덱스 반환
ll query(ll s, ll e, ll n, ll l, ll r) {
  if (r < s || e < l) return LINF;
  if (l <= s && e <= r) return tree[n];

  ll mid = (s + e) / 2;
  ll left = query(s, mid, 2 * n, l, r);
  ll right = query(mid + 1, e, 2 * n + 1, l, r);
  
  if (left == LINF) left = l;
  if (right == LINF) right = r;
  return (arr[left] > arr[right]) ? right : left;
}

ll maxArea(ll l, ll r) {
  ll mid = query(0, N - 1, 1, l, r); // 최소 인덱스 반환
  ll ans = arr[mid] * (r - l + 1);

  if (l < mid) ans = max(ans, maxArea(l, mid - 1));
  if (mid < r) ans = max(ans, maxArea(mid + 1, r));
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  init(0, N - 1, 1);

  cout << maxArea(0, N - 1);
}

// ■ check list ■
// 1. overflow, data type, memset. ==, >=, >
// 2. first visit, % MOD