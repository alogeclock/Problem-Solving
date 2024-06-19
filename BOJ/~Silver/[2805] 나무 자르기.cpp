#include <bits/stdc++.h>
using namespace std;
#define MAX_TREES 1000001

int arr[MAX_TREES];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, M;
  cin >> N >> M;

  int max_height = 0;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    max_height = max(arr[i], max_height);
  }

  long long first = 0, end = max_height, mid;
  long long sum;
  while (first <= end) {
    sum = 0, mid = (first + end) / 2;

    for (int i = 0; i < N; i++) {
      if (arr[i] - mid > 0) sum += arr[i] - mid;
    }

    if (sum == M) {
      cout << mid << '\n';
      return 0;
    } else if (sum > M) {
      first = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  if (sum < M) mid--;

  cout << mid << '\n';

  return 0;
}