// idea: find biggest number not with sorting, but with stack
// stack<pair<int, int>> 활용법

#include <bits/stdc++.h>
#define MAX_SEQ_NUMBER 1000001
using namespace std;

int arr[MAX_SEQ_NUMBER];
int nge[MAX_SEQ_NUMBER];
stack<pair<int, int>> s;  // 오큰수 값, 주소

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  int i = 0;

  for (int i = 0; i < N; i++) {
    while (!s.empty() && arr[i] > s.top().first) {
      nge[s.top().second] = arr[i];
      s.pop();
    }

    s.push({arr[i], i});
  }

  while (!s.empty()) {
    nge[s.top().second] = -1;
    s.pop();
  }

  for (int i = 0; i < N; i++) cout << nge[i] << " ";

  return 0;
}