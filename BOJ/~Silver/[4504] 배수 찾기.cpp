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

  ll N; cin >> N;

  ll op;
  while (cin >> op) {
    if (!op) return 0;
    cout << op << " is" << (op % N == 0 ? " " : " NOT ") << "a multiple of " << N << ".\n";
  }
}