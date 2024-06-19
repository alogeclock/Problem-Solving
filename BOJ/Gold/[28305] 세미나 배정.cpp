// idea: binary search, array management
// 강의실의 수 길이의 배열에 세미나가 끝나는 시간을 계속해서 갱신
// debugging: mid 변수가 변화하면서 (i- mid == mid) mid += mid; 고장

#include <bits/stdc++.h>
using namespace std;

int N, T;
int arr[200001];

bool Check(int mid) {
  if (!mid) return 0;
  int room[200001];

  int raw_mid = mid;

  for (int i = 0; i < N; i++) {
    if (i - mid == raw_mid) mid += mid;
    if (i < mid)
      room[i] = arr[i] + T;  // 가능한 최소 시작 시간
    else {
      if (room[i - mid] >= arr[i] + T) return false;
      if (room[i - mid] <= arr[i])
        room[i - mid] = arr[i] + T;
      else
        room[i - mid] = room[i - mid] + T;
    }
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> T;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];  // 가능한 최소 시작시간
    arr[i] = max(1, arr[i] - T + 1);
  }

  sort(arr, arr + N);  // 시작시간 기준 정렬

  int lp = 0, rp = N;  // F-T 문제, rp가 모든 범위를 훑도록 함
  while (lp + 1 < rp) {
    int mid = (lp + rp) / 2;
    if (Check(mid))  // 성립 = 더 작아져도 됨
      rp = mid;
    else
      lp = mid;
  }

  cout << rp << '\n';

  return 0;
}