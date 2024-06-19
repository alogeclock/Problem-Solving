#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define PINF 1000000007

const int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int vst[305][305];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int len;
    int d_row, d_col;
    int front = 0, rear = 0;
    int q[200005][3];

    memset(vst, -1, sizeof(vst)); // #include <string.h>
    cin >> len >> q[0][0] >> q[0][1] >> d_row >> d_col;
    q[0][2] = 0;

    while (front <= rear) {
      int cr = q[front][0];
      int cc = q[front][1];
      int dst = q[front][2];

      vst[cr][cc] = true;
      if (cr == d_row && cc == d_col) {
        cout << dst << '\n';
        break;
      }

      for (int i = 0; i < 8; i++) {
        int nr = cr + dr[i];
        int nc = cc + dc[i];
        int ndst = dst + 1;

        if (nr < 0 || nc < 0 || nr >= len || nc >= len)
          continue;
        if (vst[nr][nc] != -1 && ndst >= vst[nr][nc]) // 방문했고, 회수가 더 짧음
          continue;

        vst[nr][nc] = true;
        rear++;
        q[rear][0] = nr, q[rear][1] = nc, q[rear][2] = ndst;
      }
      front++;
    }
  }
}