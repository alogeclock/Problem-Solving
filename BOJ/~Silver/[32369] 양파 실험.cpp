#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ll N, A, B;
  cin >> N >> A >> B;
  ll a = 1, b = 1;

  for (int i = 0; i < N; i++) {
    a += A; b += B;
    if (a < b) swap(a, b);
    else if (a == b) b--;
  }

  cout << a << ' ' << b;
}