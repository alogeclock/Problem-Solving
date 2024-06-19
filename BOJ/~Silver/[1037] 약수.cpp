#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define PINF 1000000007

int factor[51];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) cin >> factor[i];

  sort(factor, factor + N);

  cout << factor[0] * factor[N - 1];
}
