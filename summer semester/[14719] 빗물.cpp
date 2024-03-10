// idea: stack, two pointer
// 어떻게 해야 좀 더 깔끔하게 풀 수 있을까?

#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define PINF 1000000007

int arr[505];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N, M;
  cin >> M >> N;

  for (int i = 0; i < N; i++) cin >> arr[i];

  stack<pair<int, int>> s;  // pair<값, 값의 주소>
  s.push({arr[0], 0});
  int sum = 0, local_max = arr[0], local_max_idx = 0;

  for (int cur = 1; cur < N; cur++) {
    // 값 증가 시 스택의 같은 값까지의 거리 * 증분
    if (arr[cur] > arr[cur - 1]) {
      while (!s.empty() && s.top().first <= arr[cur]) s.pop();

      int height, dst;
      if (s.empty()) {
        height = local_max - arr[cur - 1];
        dst = cur - local_max_idx - 1;
      } else {
        height = arr[cur] - arr[cur - 1];
        dst = cur - s.top().second - 1;
      }
      sum += dst * height;
    }

    s.push({arr[cur], 0});
    if (arr[cur] > local_max) {
      local_max = arr[cur], local_max_idx = cur;
    }
  }

  cout << sum;
}