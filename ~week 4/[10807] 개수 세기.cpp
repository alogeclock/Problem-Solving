#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int num[1001] = {0};
  int N;
  cin >> N;

  while (N--) {
    int a;
    cin >> a;
    num[a + 100]++;
  }

  cin >> N;
  cout << num[N + 100];

  return 0;
}