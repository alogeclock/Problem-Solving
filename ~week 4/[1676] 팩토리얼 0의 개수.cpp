#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, count = 0;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    int j = i;
    while (j && j % 5 == 0) {
      j /= 5;
      count++;
    }
  }

  cout << count;

  return 0;
}