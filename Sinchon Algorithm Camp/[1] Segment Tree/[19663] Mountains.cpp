// idea: segment tree
// 1) 배열을 높이 순서로 정렬하고, 낮은 순서대로 방문
// 2) 방문한 높이의 인덱스에 대해 왼쪽, 오른쪽에 대해 vst 배열 재귀 탐색
// 3) vst[] 배열을 세그먼트 트리로 계산하는 한편, update()로 수정

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007LL

pll height[300030];
ll tree[1200120];

ll query(ll s, ll e, ll n, ll l, ll r) {
  if (r < s || e < l) return 0;
  if (l <= s && e <= r) return tree[n];
  ll mid = (s + e) / 2;
  return query(s, mid, 2 * n, l, r) + query(mid + 1, e, 2 * n + 1, l, r);
}

void update(ll s, ll e, ll n, ll idx) {
  if (idx < s || idx > e) return;
  if (s == e) { tree[n] = 1; return; }
  ll mid = (s + e) / 2;
  update(s, mid, 2 * n, idx), update(mid + 1, e, 2 * n + 1, idx);
  tree[n] = tree[2 * n] + tree[2 * n + 1];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll N; cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> height[i].first;
    height[i].second = i;
  }
  sort(height, height + N);

  // 어차피 초기 방문 상태는 모두 0이기 때문에 segTree의 init() 불필요

  stack<ll> s; // 방문 상태를 갱신할 인덱스를 저장하는 stack
  ll prev = height[0].first, ans = 0;

  for (int i = 0; i < N; i++) {
    auto [value, idx] = height[i];
    
    if (prev != value) {
      while (s.size()) {
        update(0, N - 1, 1, s.top());
        s.pop();
      }
    }

    ll left = query(0, N - 1, 1, 0, idx - 1);
    ll right = query(0, N - 1, 1, idx + 1, N - 1);
    ans += left * right;
    s.push(idx);
    prev = value;
  }

  cout << ans;
}

// ■ check list ■
// 1. overflow, data type, memset. ==, >=, >
// 2. first visit, % MOD