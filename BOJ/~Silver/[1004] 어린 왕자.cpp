// idea: 출발점이나 도착점 중 하나만 포함하는 원 구하기

#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define PINF 1000000007

// start_row, start_col, destination_row, destination_col
int sr, sc, dr, dc;
int pr, pc, rad;  // planet_row, planet_col, radius
int pr_min, pr_max, pc_min, pc_max;

// 거리를 통해 행성계 안에 있는지 확인
bool isInPlanetarySystem(int r, int c) {
  r = r - pr, c = c - pc;
  r *= r, c *= c;
  return (r + c < rad * rad);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int count = 0;
    cin >> sr >> sc >> dr >> dc;
    int planet;
    cin >> planet;
    while (planet--) {
      cin >> pr >> pc >> rad;
      // 출발점, 도착점이 포함되지만, 둘 다 포함되선 안 됨

      bool flag_src = isInPlanetarySystem(sr, sc);
      bool flag_des = isInPlanetarySystem(dr, dc);
      if ((flag_src && !flag_des) || (!flag_src && flag_des)) count++;
    }
    cout << count << '\n';
  }
}
