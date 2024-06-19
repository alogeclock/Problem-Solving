
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, K;
  queue<int> rats;
  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    rats.push(i + 1);
  }

  int size = N, alive;
  while (N > 1) {
    alive = rats.front();
    for (int i = 0; i < K; i++) {
      rats.pop();
      N--;
      if (N == 0) break;
    }
    rats.push(alive);
    N++;
  }

  cout << alive;

  return 0;
}