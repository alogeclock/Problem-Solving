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

  for (int i = 0; i < N; i++)
    cin >> arr[i];

  stack<pair<int, int>> s; // pair<값, 값의 주소>
  s.push({arr[0], 0});
  int sum = 0;

  for (int cur = 1; cur < N; cur++) {
    int range_max = 0;
    while (s.size()) {
      if (range_max < s.top().first) {
        int dst = cur - s.top().second - 1;
        int height = min(s.top().first, arr[cur]) - range_max;
        sum += dst * height;
        range_max = s.top().first;
      }
      if (arr[cur] < s.top().first)
        break;
      s.pop();
    }

    s.push({arr[cur], cur});
  }

  cout << sum;
}