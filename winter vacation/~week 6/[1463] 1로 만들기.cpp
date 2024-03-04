#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX_NUM 1000001
#define INF 0x3f3f3f3f

int dp[MAX_NUM];

int rdp(int k, int cur) {
  if (k == 1) return cur;
  if (dp[k] != -1) return dp[k];

  int ret = INF;
  if (k % 3 == 0) ret = min(ret, rdp(k / 3, cur + 1));
  if (k % 2 == 0) ret = min(ret, rdp(k / 2, cur + 1));
  ret = min(ret, rdp(k - 1, cur + 1));

  dp[k] = ret;
  return ret;
}

int main() {
  int X;
  cin >> X;

  memset(dp, -1, sizeof(dp));

  cout << rdp(X, 0);

  return 0;
}