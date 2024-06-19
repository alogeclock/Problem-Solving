#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define PINF 1000000007

bool compare(int a, int b) {
  return a > b;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int rgb[3];
  cin >> rgb[0] >> rgb[1] >> rgb[2];

  int box = 0;
  for (int i = 0; i < 3; i++) {
    box += rgb[i] / 3;
    rgb[i] %= 3;
  }

  sort(rgb, rgb + 3, compare);

  if (rgb[1] == 0 && rgb[0] != 0)
    box++;
  else
    box += max({rgb[0], rgb[1], rgb[2]});

  cout << box;
}