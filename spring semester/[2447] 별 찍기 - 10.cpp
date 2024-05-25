// idea: 옆으로 주어졌다고 항상 옆으로 고려하지 않는다. 위에서부터 고려

#include <bits/stdc++.h>
using namespace std;

int arr[6600][6600]; // 172MB

void rec(int x, int y, int n, int c) {
  if (n == 1) {
    arr[x][y] = c;
    return;
  }

  n /= 3;
  if (c == 1) {
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) {
        if (i == j && i == 1) continue;
        rec(x + n * i, y + n * j, n, 1);
      }
    rec(x + n * 1, y + n * 1, n, 0);
    return;
  } else {
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        rec(x + n * i, y + n * j, n, 0);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  rec(0, 0, N, 1);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      if (arr[i][j] == 1)
        cout << '*';
      else
        cout << ' ';
    cout << '\n';
  }
}