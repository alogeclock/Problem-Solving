#include <bits/stdc++.h>
using namespace std;
#define MAX_NUMBER 200001

int arr[MAX_NUMBER];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, K;  // 길이, 겹치는 개수
  cin >> N >> K;

  for (int i = 0; i < N; i++) cin >> arr[i];
  int maxLen = 1;
  int len = 0, input;
  map<int, int> m;  // 숫자, 중복 개수

  for (int i = 0, j = 0; i < N;) {
    if (j == N) break;
    if (m[arr[j]] <= K) {
      m[arr[j++]]++;
      len++;
    }
    while (m[arr[j - 1]] > K && i < j) {
      m[arr[i++]]--;
      len--;
    }
    maxLen = max(len, maxLen);
  }

  cout << maxLen << '\n';

  return 0;
}