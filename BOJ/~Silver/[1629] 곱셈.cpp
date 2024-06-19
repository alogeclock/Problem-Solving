#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF ((int)1e9 + 7)
#define ll long long

ll A, B, C;

ll pow(ll A, ll B) {
  if (!B) return 1;
  ll ret = pow(A, B / 2) % C;
  ret = (ret * ret) % C;
  if (B % 2) ret = ret * A % C;
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> A >> B >> C;

  cout << pow(A, B);

  return 0;
}