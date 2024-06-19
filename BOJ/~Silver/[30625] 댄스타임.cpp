#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, M;
  cin >> N >> M;

  int one = 0;
  long long perfect = 1, wrong = 0;
  for (int i = 0; i < N; i++) {
    int dance, dir;
    cin >> dance >> dir;
    if (dir == 0) {  // 같은 춤
      wrong = (wrong + perfect * (M - 1)) % INF;
    }
    if (dir == 1) {  // 다른 춤
      wrong = (perfect + wrong * (M - 1)) % INF;
      perfect = (perfect * (M - 1)) % INF;
      one++;
    }
  }

  if (one > 1 && M == 1) {
    cout << 0 << '\n';
    return 0;
  }

  cout << (perfect + wrong) % INF << '\n';

  return 0;
}