#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  ll N, M; cin >> N >> M;
  string s; cin >> s;
  
  ll lv = 0, cnt = 0;
  for (auto c : s) {

    if (lv % 2 == 0) {
      if (c == 'I') lv++;
      else lv = 0;
    }
    else {
      if (c == 'O') lv++;
      else lv = 1;
    }

    if (lv == 2 * N + 1) {
      lv -= 2;
      cnt++;
    }
  }

  cout << cnt;
}