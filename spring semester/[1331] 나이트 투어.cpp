#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define PINF 1000000007

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N, M;
  cin >> N >> M;

  if (N == 1 || M == 1)
    cout << 1;

  else if (N == 2) // 왕복 불가
    cout << min(4, (M - 1) / 2 + 1);

  else {
    if (M < 6)
      cout << min(4, M);
    else
      cout << M - 2;
  }
}