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

  int N;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < i; j++) cout << '*';
    for (int j = 0; j < N - i; j++) cout << "  ";
    for (int j = 0; j < i; j++) cout << '*';
    cout << '\n';
  }

  for (int i = N - 1; i >= 1; i--) {
    for (int j = 0; j < i; j++) cout << '*';
    for (int j = 0; j < N - i; j++) cout << "  ";
    for (int j = 0; j < i; j++) cout << '*';
    cout << '\n';
  }
}