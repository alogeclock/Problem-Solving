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

  string N;
  cin >> N;

  if (N == "0") cout << 0;

  int flag = 0;
  for (int i = 0; i < N.length(); i++) {
    int num = N[i] - 48, base = 4;
    for (int j = 0; j < 3; j++) {
      int ans = num / base;
      if (ans) flag = 1; // 첫 1이 출력되기 전까지 출력 금지
      if (flag) cout << num / base;
      num %= base;
      base /= 2;
    }
  }
}