
// idea: lis, dp, binary search

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

ll arr[1000100], dp[1000100], vst[1000100];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  memset(dp, 0x3f, sizeof(dp));
  dp[0] = -LINF;

  ll N; cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    auto idx = lower_bound(dp, dp + N + 5, arr[i]) - dp; // F-T 우측
    dp[idx] = arr[i]; // 방문한 인덱스 저장
    vst[i] = idx; // 방문 배열에 현재 값으로 만들 수 있는 최장 길이 부분수열 저장
  }

  auto idx = lower_bound(dp, dp + N + 5, LINF) - dp - 1; // F-T 좌측
  cout << idx << '\n';
  
  int size = idx; vector<ll> v;
  for (int i = N - 1; i >= 0; i--) {
    if (vst[i] == size) {
      size--;
      v.push_back(arr[i]);
    }
  }

  for (auto it = v.rbegin(); it < v.rend(); it++) cout << *it << ' ';
}
