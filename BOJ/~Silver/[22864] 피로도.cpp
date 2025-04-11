#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ll A, B, C, M;
  cin >> A >> B >> C >> M;

  ll total_work = 0, fatigue = 0;
  for (int t = 0; t < 24; t++) {
    if (fatigue + A <= M) {
        fatigue += A;
        total_work += B;
      }
    else
      fatigue = max(fatigue - C, 0LL);
  }

  cout << total_work;
}
