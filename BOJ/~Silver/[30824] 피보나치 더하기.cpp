#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define PINF 1000000007

ll fibo[105];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;

  fibo[0] = 1;
  fibo[1] = 1;
  fibo[2] = 2;

  int idx;  // 78번째 값에서 10^16을 넘어섬
  for (int i = 3; fibo[i - 1] <= (ll)1e16; i++) {
    idx = i;
    fibo[i] = fibo[i - 1] + fibo[i - 2];
  }

  while (T--) {
    ll input, k;
    cin >> k >> input;

    bool flag = false;

    if (k == 1) {
      for (int i = 0; input >= fibo[i]; i++) {
        if (input == fibo[i]) {
          flag = true;
          break;
        }
      }
    }

    else if (k == 2) {
      for (int i = 0; input >= fibo[i]; i++) {
        for (int j = 0; input >= fibo[i] + fibo[j]; j++) {
          if (input == fibo[i] + fibo[j]) {
            flag = true;
            break;
          }
        }
        if (flag) break;
      }
    }

    else {
      for (int i = 0; input >= fibo[i]; i++) {
        for (int j = 0; input >= fibo[i] + fibo[j]; j++) {
          for (int k = 0; input >= fibo[i] + fibo[j] + fibo[k]; k++)
            if (input == fibo[i] + fibo[j] + fibo[k]) {
              flag = true;
              break;
            }
          if (flag) break;
        }
        if (flag) break;
      }
    }

    if (flag)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}