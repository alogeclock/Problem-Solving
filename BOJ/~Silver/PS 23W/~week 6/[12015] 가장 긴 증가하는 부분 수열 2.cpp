// idea: dp, LIS(Longest Increasing Subsequence)

// lis[i]의 idx: 부분수열의 길이
// lis[i]: i 길이의 부분수열의 마지막 값(=최대값)

// 1. 매 i마다 수열 길이(lis의 길이)를 갱신하거나
// 2. 길이가 n인 부분수열의 최대값(마지막 값)을 더 작게 갱신할 수 있음
// 3. 이분 탐색을 통해 arr[i]보다 작은 lis[i]값을 효율적으로 탐색할 수 있음

// lis[i]를 갱신하기 위해 INF값으로 초기화, lis[0]을 0으로 초기화

// debugging: memset은 0x3f3f3f3f, -1, 0, 1 등의 특수한 값만 쓰는 게 좋음
// memset은 값의 마지막 8비트만 자른 뒤 바이트 단위로 똑같이 입력함

#include <bits/stdc++.h>
#define MAX_NUM 1000010
#define INF 0x3f3f3f3f
using namespace std;

int arr[MAX_NUM], lis[MAX_NUM];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  memset(lis, INF, sizeof(lis));
  lis[0] = 0;

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    auto idx = lower_bound(lis, lis + N + 5, arr[i]) - lis;  // F-T 문제: 우측
    lis[idx] = arr[i];
  }

  auto idx = lower_bound(lis, lis + N + 5, INF) - lis;  // F-T 문제: 좌측
  cout << idx - 1;
}