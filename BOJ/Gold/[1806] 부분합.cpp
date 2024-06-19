#include <bits/stdc++.h>
using namespace std;
#define MAX_NUMBER 100001

int stat[MAX_NUMBER];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> stat[i];
  }

  int len = 1e9;  // 가장 짧은 길이 구하기
  int sum = stat[0];
  bool flag = 0;
  for (int i = 0, j = 0; i < N;) {
    if (sum >= M) {
      flag = 1;
      len = min(len, j - i + 1);
      if (i < j)
        sum -= stat[i++];
      else  // i == j면 sum이 M보다 커도 i를 늘리지 못함
        sum += stat[++j];
    } else {
      if (j > N - 1) break;
      sum += stat[++j];
    }
  }

  if (flag)
    cout << len << '\n';
  else
    cout << 0 << '\n';

  return 0;
}