#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int basket[101];

  for (int i = 1; i <= 100; i++) {
    basket[i] = i;
  }

  int N, M;
  cin >> N >> M;

  for (int i = 1; i <= M; i++) {
    int a, b;
    cin >> a >> b;
    int temp = basket[a];
    basket[a] = basket[b];
    basket[b] = temp;
  }

  for (int i = 1; i <= N; i++) {
    cout << basket[i] << " ";
  }

  return 0;
}