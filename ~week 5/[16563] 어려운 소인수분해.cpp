// idea: eratosthenes' sieve → prime factors

#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)5e6 + 1)

int arr[MAX_NUM];

void sieve() {
  for (int i = 2; i < MAX_NUM; i++) {
    if (!arr[i])
      for (int j = i; j < MAX_NUM; j += i) arr[j] = i;
  }
}

void calculate(int input) {}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;

  sieve();

  for (int i = 0; i < N; i++) {
    int input;
    cin >> input;

    vector<int> factors;
    while (input > 1) {
      factors.push_back(arr[input]);
      input /= arr[input];
    }

    sort(factors.begin(), factors.end());

    for (auto iter : factors) {
      cout << iter << ' ';
    }
    cout << '\n';
  }

  return 0;
}