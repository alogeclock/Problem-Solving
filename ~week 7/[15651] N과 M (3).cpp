#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF ((int)1e9 + 7)
#define ll long long

int N, M;
int state[10];

void backtracking(int k) {
  if (k > M) {
    for (int i = 1; i <= M; i++) cout << state[i] << ' ';
    cout << '\n';
    return;
  }

  for (int i = 1; i <= N; i++) {
    state[k] = i;
    backtracking(k + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> N >> M;

  state[0] = 1;
  backtracking(1);
}