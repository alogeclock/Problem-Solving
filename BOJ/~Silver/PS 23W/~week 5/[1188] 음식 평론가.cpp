// idea: gcd로 풀 수 있지만, 규칙을 찾아서 풀 수도 있음
// debugging: 소시지를 한 번 잘랐을 때 마무리가 되지 않을 경우를 고려

#include <bits/stdc++.h>
using namespace std;

int main() {
  int sausage, critic, cut = 1;
  cin >> sausage >> critic;

  int total = 0;

  while (sausage % critic != 0 && critic > 0) {
    cut = 1;
    sausage %= critic;
    for (double i = 2.0; i <= 100; i++) {
      if ((double)sausage / critic >= 1 / (double)i) break;
      cut++;
    }
    total += cut * sausage;
    critic -= cut * sausage;
  }

  cout << total << '\n';

  return 0;
}