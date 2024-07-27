// idea: segment tree(basics)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000009LL
#define MAX_NUMBER 1000000

// 공간 복잡도: 원소의 수 N보다 큰 2의 거듭제곱 2^K에 대해 2*(K+1)
// 구간 합 배열의 길이는 보통 원소의 수 * 4로 설정
ll arr[MAX_NUMBER], tree[4 * MAX_NUMBER];

// start: 시작 idx, end: 끝 idx
// node: 구간 합의 왼쪽 노드, node + 1: 구간 합의 오른쪽 노드
ll init(ll start, ll end, ll node) {
  if (start == end) return tree[node] = arr[start];
  ll mid = (start + end) / 2;
  return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

// left, right: 구간 합의 범위
ll sum(ll start, ll end, ll node, ll left, ll right) {
  if (left > end || right < start) return 0; // 범위 밖
  if (left <= start && end <= right) return tree[node]; // 범위 안
  // 범위 안은 아니지만 겹치는 구간이 존재할 경우 구간을 반으로 쪼갬
  ll mid = (start + end) / 2;
  return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

// index: 구간 합을 수정하고자 하는 노드
// dif: index번째 수를 변경할 때 발생하는 값의 차이 (5 → 7이면 +2, 5 → 3이면 -2)
void update(ll start, ll end, ll node, ll index, ll dif) {
  if (index < start || index > end) return;
  tree[node] += dif;
  
  if (start == end) return;
  ll mid = (start + end) / 2;
  update(start, mid, node * 2, index, dif); 
  update(mid + 1, end, node * 2 + 1, index, dif);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  // M: update query, K: prefix sum query
  ll N, M, K; cin >> N >> M >> K;
  for (int i = 0; i < N; i++) cin >> arr[i];
  
  ll T = M + K;
  init(0, N - 1, 1);

  while (T--) {
    ll a, b, c; cin >> a >> b >> c;
    if (a == 1) {
      ll diff = c - arr[b - 1]; arr[b - 1] = c;
      update(0, N - 1, 1, b - 1, diff);
    }
    else cout << sum(0, N - 1, 1, b - 1, c - 1) << '\n';
  }
}

// ■ check list ■
// 1. overflow, data type, memset. ==, >=, >
// 2. first visit, % MOD