#include <bits/stdc++.h>
using namespace std;
#define MAX_NUMBER 1000001

long long N[MAX_NUMBER];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int T;
  cin >> T;

  N[0] = 1;
  N[1] = 2;
  N[2] = 4;

  for (int i = 3; i < 1000001; i++)
    N[i] = (N[i - 1] + N[i - 2] + N[i - 3]) % 1000000009;

  while (T--) {
    int input;
    cin >> input;
    cout << N[input - 1] << "\n";
  }

  return 0;
}