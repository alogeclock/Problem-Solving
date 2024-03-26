#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define PINF 1000000007

bool damaged[15];
bool two_kayak[15];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N, S, R;  // 팀의 수, 카약 손상 팀의 수, 카약 휴대 팀의 수
  cin >> N >> S >> R;

  int team, ans = 0;
  for (int i = 0; i < S; i++) {
    cin >> team;
    damaged[team - 1] = true;
    ans++;
  }

  for (int i = 0; i < R; i++) {
    cin >> team;
    two_kayak[team - 1] = true;
  }

  for (int i = 0; i < N; i++) {
    if (two_kayak[i] && damaged[i]) {
      ans--;
      damaged[i] = false;
      two_kayak[i] = false;
    }
  }

  for (int i = 0; i < N; i++) {
    if (two_kayak[i]) {
      if (i > 0 && damaged[i - 1]) {
        ans--;
        damaged[i - 1] = false;
        two_kayak[i] = false;
      } else if (i < N - 1 && damaged[i + 1]) {
        ans--;
        damaged[i + 1] = false;
        two_kayak[i] = false;
      }
    }
  }

  cout << ans;
}