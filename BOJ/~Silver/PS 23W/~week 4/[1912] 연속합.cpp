#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM 100001

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;

  int seq[MAX_NUM], left[MAX_NUM];

  int val = -1e9;
  for (int i = 1; i <= N; i++) {
    cin >> seq[i];
    if ((left[i - 1] + seq[i]) < 0)
      left[i] = seq[i];
    else
      left[i] = max(left[i - 1] + seq[i], seq[i]);

    if (val < left[i]) val = left[i];
  }

  cout << val << "\n";

  return 0;
}