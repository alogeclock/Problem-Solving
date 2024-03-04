// idea: recursive, map 재귀는 '시작점 찍기의 반복'

#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF ((int)1e9 + 7)
#define ll long long

int N;
bool m[3100][6200];  // m[0]은 무시

void paint(int r, int c, int k) {
  if (k == 3) {  // 삼각형 찍기
    m[r - 2][c + 2] = 1;
    m[r - 1][c + 1] = m[r - 1][c + 3] = 1;
    m[r][c] = m[r][c + 1] = m[r][c + 2] = m[r][c + 3] = m[r][c + 4] = 1;
    return;
  }
  int base = k / 2;
  // 삼각형의 시작점 찍기
  paint(r - base, c + base, base);
  paint(r, c + k, base);
  paint(r, c, base);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N;
  paint(N, 0, N);  // 시작점을 찍어주는 재귀

  for (int r = 1; r <= N; r++) {
    for (int c = 0; c < 2 * N; c++) {
      if (m[r][c])
        cout << '*';
      else
        cout << ' ';
    }
    cout << '\n';
  }
}