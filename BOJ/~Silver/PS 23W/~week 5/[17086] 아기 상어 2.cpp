#include <bits/stdc++.h>
using namespace std;

const int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

struct Point {
  int row, col, dst;
  Point(int r, int c, int w) : row(r), col(c), dst(w){};
};

int N, M;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int dst[51][51];
  fill(dst[0], dst[51], 1e9);  // 2차원 배열 초기화

  cin >> N >> M;

  queue<Point> q;

  int input;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> input;
      if (input) {
        q.push(Point(i, j, 0));
        dst[i][j] = 0;
      }
    }
  }

  while (q.size()) {
    Point cur = q.front();
    q.pop();

    if (dst[cur.row][cur.col] < cur.dst) continue;

    dst[cur.row][cur.col] = cur.dst;

    for (int i = 0; i < 8; i++) {
      int nr = cur.row + dr[i];
      int nc = cur.col + dc[i];
      int ndst = cur.dst + 1;

      if (nr <= 0 || nc <= 0 || nr > N || nc > M) continue;
      if (dst[nr][nc] > ndst) {
        dst[nr][nc] = ndst;
        q.push(Point(nr, nc, ndst));
      }
    }
  }

  int val = 0;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) val = max(val, dst[i][j]);

  cout << val << '\n';

  return 0;
}