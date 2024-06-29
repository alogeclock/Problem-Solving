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

  int K; cin >> K;
  stack<int> s;

  for (int i = 0; i < K; i++) {
    int x; cin >> x;
    if (x != 0) s.push(x);
    else s.pop();
  }

  int sum = 0;
  while (s.size()) {
    sum += s.top();
    s.pop();
  }

  cout << sum;
}