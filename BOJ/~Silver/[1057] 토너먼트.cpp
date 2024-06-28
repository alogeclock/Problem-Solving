// idea: two pointer

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007

ll lv, rv; // 왼쪽 번호, 오른쪽 번호

void split(int l, int r, int range) {
  int half = range / 2;
  if (r - half >= rv)
    split(l, r - half, half);
  else if (l + half <= lv)
    split(l + half, r, half);
  else {
    int count = 0;
    while (range /= 2) {
      count++;
    }
    cout << count;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll N, p, q;
  cin >> N >> p >> q;
  lv = min(p, q), rv = max(p, q);

  ll range = 1;
  while (range < N) {
    range *= 2;
  }

  split(1, range, range);
}