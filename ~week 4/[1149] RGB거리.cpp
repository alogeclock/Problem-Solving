#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int T;
  cin >> T;

  int can_select[3];  // 1, 2, 3을 고를 수 있는 숫자 중 가장 작은 숫자
  int result[3];  // 1, 2, 3을 각각 선택한 결과
  int input[3];

  for (int i = 0; i < T; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> input[j];
      if (i == 0)
        result[j] = input[j];
      else
        result[j] = can_select[j] + input[j];
    }
    can_select[0] = (result[1] > result[2]) ? result[2] : result[1];
    can_select[1] = (result[0] > result[2]) ? result[2] : result[0];
    can_select[2] = (result[0] > result[1]) ? result[1] : result[0];
  }

  int min = 1e9;
  for (int i = 0; i < 3; i++) {
    if (min > result[i]) min = result[i];
  }

  cout << min << "\n";

  return 0;
}