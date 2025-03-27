#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll N, K;
  cin >> N >> K;

  for (int i = 1; i <= N; i++) {
    if (N % i == 0) {
      if (K == 1) {
        cout << i;
        return 0;
      }
      else K--;
    }
  }

  cout << 0;
}