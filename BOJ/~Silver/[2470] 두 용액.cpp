// 특성값이 0에 가장 가까운 용액 만들기
// 출력: 오름차순, 두 용액(둘 이상일 경우 아무 것이나)

#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e5 + 1)

int arr[MAX_NUM];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + N);  // 오름차순

  int min_lp = 0, min_rp = N - 1;
  int min = 2e9 + 1;
  for (int lp = 0, rp = N - 1; lp < rp;) {
    if (min > abs(arr[lp] + arr[rp])) {
      min_lp = lp, min_rp = rp;
      min = abs(arr[lp] + arr[rp]);
    }
    if (arr[lp] + arr[rp] > 0) {  // 산성이 더 강함
      rp--;
    } else {
      lp++;
    }
  }

  cout << arr[min_lp] << ' ' << arr[min_rp] << '\n';

  return 0;
}