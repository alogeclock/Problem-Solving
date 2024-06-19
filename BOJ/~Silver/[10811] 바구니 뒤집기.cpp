#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, i, j, k, arr[101];
  cin >> N >> M;
  for (k = 1; k <= N; k++) arr[k] = k;
  while (M--) cin >> i >> j, reverse(arr + i, arr + j + 1);
  for (k = 1; k <= N; k++) cout << arr[k] << ' ';
}