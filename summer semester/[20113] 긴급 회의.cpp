#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define PINF 1000000007

int arr[105];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N;
  cin >> N;  // 크루원의 수

  int num, max_num = 0, idx = -1;
  bool skip_flag = false;
  for (int i = 0; i < N; i++) {
    cin >> num;
    if (num == 0) continue;
    arr[num]++;
    if (arr[num] > max_num) {
      skip_flag = false;
      max_num = arr[num];
      idx = num;
    } else if (arr[num] == max_num) {
      skip_flag = true;
    }
  }

  if (skip_flag || idx == -1)
    cout << "skipped";
  else
    cout << idx;
}