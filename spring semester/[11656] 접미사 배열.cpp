#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define PINF 1000000007

string suffix[1005];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  string s;
  cin >> s;

  int len = s.length();

  for (int i = 0; i < len; i++) {
    for (int j = i; j < len; j++) {
      suffix[i] += s[j];
    }
  }
  sort(suffix, suffix + len);

  for (int i = 0; i < len; i++) cout << suffix[i] << '\n';
}