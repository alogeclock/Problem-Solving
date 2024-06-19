#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM 1000001

long long f[MAX_NUM];
long long g[MAX_NUM];

void sieve() {
  for (int i = 1; i < MAX_NUM; i++) {
    for (int j = i; j < MAX_NUM; j += i) f[j] += i;
    g[i] = g[i - 1] + f[i];
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  sieve();

  int T;
  cin >> T;

  while (T--) {
    int input;
    cin >> input;
    cout << g[input] << '\n';
  }
  return 0;
}