#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007

int cube[6][4] = {{0, 1, 4, 5}, {1, 3, 5, 7}, {4, 5, 6, 7}, {0, 1, 2, 3}, {2, 3, 6, 7}, {0, 2, 4, 6}};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll T;
  cin >> T;

  while (T--) {
    int dot[4];
    cin >> dot[0] >> dot[1] >> dot[2] >> dot[3];

    for (int i = 0; i < 6; i++) {
      int vst[4] = {0, 0, 0, 0};

      for (int j = 0; j < 4; j++) {
        if (dot[j] == cube[i][0]) vst[0] = 1;
        if (dot[j] == cube[i][1]) vst[1] = 1;
        if (dot[j] == cube[i][2]) vst[2] = 1;
        if (dot[j] == cube[i][3]) vst[3] = 1;
      }

      if (vst[0] & vst[1] & vst[2] & vst[3]) {
        printf("YES\n");
        goto LOOP;
      }
    }
    printf("NO\n");

  LOOP:;
  }
}