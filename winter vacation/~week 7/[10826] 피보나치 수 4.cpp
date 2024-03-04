// idea: adder

#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e7 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define PINF 1000000007

ll N;
string prv, cur, nxt;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N;

  if (!N) {
    cout << 0;
    return 0;
  }

  prv = "1", cur = "1";
  for (int i = 2; i < N; i++) {
    char carry = false;
    nxt.clear();
    for (int j = 0; j < (int)cur.length(); j++) {
      int prevDigit = 0;
      if (prv[j]) prevDigit = prv[j] - 48;
      int curDigit = cur[j] + prevDigit + (int)carry - 48;
      carry = false;
      if (curDigit > 9) curDigit -= 10, carry = true;
      nxt.push_back((char)(curDigit + 48));
    }
    if (carry) {
      nxt.push_back('1');
    }
    prv = cur;
    cur = nxt;
  }

  reverse(cur.begin(), cur.end());
  cout << cur;
}