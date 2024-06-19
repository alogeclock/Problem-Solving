#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N = 0, odd = 1e9;  // 최소 홀수
  cin >> N;

  int sum = 0;
  for (int i = 0; i < N; i++) {
    int val;
    cin >> val;
    if (val % 2 == 1 && val < odd) odd = val;
    sum += val;
  }

  if (sum % 2 == 0)
    cout << sum;
  else if (odd == 1e9)
    cout << 0;
  else
    cout << sum - odd;

  return 0;
}