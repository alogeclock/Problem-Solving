// idea: two pointer
// 왼쪽 값을 고정(for문 돌리기)한 채 mp, rp를 움직이기

#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM 5001

long long arr[MAX_NUM];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  srand((unsigned)time(NULL));

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + N);  // 오름차순

  int min_lp = 0, min_rp = N - 1, min_mp = 1;
  long long min = 3e9 + 1;

  for (int lp = 0; lp < N - 2; lp++) {
    for (int mp = lp + 1, rp = N - 1; mp < rp;) {
      if (min > abs(arr[lp] + arr[mp] + arr[rp])) {
        min_lp = lp, min_mp = mp, min_rp = rp;
        min = abs(arr[lp] + arr[mp] + arr[rp]);
      }
      if (arr[lp] + arr[mp] + arr[rp] > 0) {  // 산성이 더 강함
        rp--;
      } else {
        mp++;
      }
    }
  }

  cout << arr[min_lp] << ' ' << arr[min_mp] << ' ' << arr[min_rp] << '\n';

  return 0;
}