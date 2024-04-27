#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define PINF 1000000007

bool compare(const char &a, const char &b) {
  return a > b;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  string s;
  cin >> s;
  sort(s.begin(), s.end(), compare);

  int sum = 0;
  for (auto c : s) {
    sum *= 10;
    sum = (sum + (int)(c - 48)) % 30;
  }
  sum %= 30;

  if (sum == 0)
    cout << s;
  else
    cout << -1;
}