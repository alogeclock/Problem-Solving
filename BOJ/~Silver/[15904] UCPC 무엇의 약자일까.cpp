// idea: implement, string

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

  string UCPC;
  getline(cin, UCPC, '\n');

  int idx = 0;
  for (auto i : UCPC) {
    switch (idx) {
      case 0:
        if (i == 'U') idx++;
        break;
      case 1:
        if (i == 'C') idx++;
        break;
      case 2:
        if (i == 'P') idx++;
        break;
      case 3:
        if (i == 'C') idx++;
        break;
      default:
        break;
    }
  }

  (idx == 4) ? cout << "I love UCPC" : cout << "I hate UCPC";
}