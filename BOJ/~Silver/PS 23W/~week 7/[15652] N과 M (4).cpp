#include <bits/stdc++.h>
using namespace std;

int N, M;
int state[10];
int vst[10];

void backtracking(int k) {
  if (k > M) {
    for (int i = 1; i <= M; i++) cout << state[i] << ' ';
    cout << '\n';
    return;
  }
  for (int i = state[k - 1]; i <= N; i++) {
    if (!vst[i]) {
      state[k] = i;
      backtracking(k + 1);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N >> M;
  state[0] = 1;
  backtracking(1);
}