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

  int N, M;  // N일, M명의 후보
  cin >> N >> M;

  ll a = 1, b = 1;
  for (int i = 0; i < N; i++) {
    a = (a * M) % PINF;
    b = (b * (M - 1)) % PINF;
  }
  ll res = (a - b) % PINF;

  if (res < 0) res += PINF;
  cout << res;
}