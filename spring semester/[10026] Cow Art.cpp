#include <bits/stdc++.h>
using namespace std;

const int dr[] = {0, 1, 0, -1}, dc[] = {1, 0, -1, 0};
char m[105][105];
int vst[105][105];
int N;

struct Point {
  int row, col;
  char value;
  Point(int r, int c, int v) : row(r), col(c), value(v){};
};

void bfs(int i, int j, int flag) {
  queue<Point> q;
  q.push(Point(i, j, m[i][j]));
  vst[i][j] = 1;

  while (q.size()) {
    auto [cr, cc, cv] = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nr = cr + dr[i];
      int nc = cc + dc[i];
      if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
      if (vst[nr][nc] == 0 && cv == m[nr][nc]) {
        vst[nr][nc] = 1;
        q.push(Point(nr, nc, cv));
      }
    }

    if (m[cr][cc] == 'G') m[cr][cc] = 'R';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      cin >> m[i][j];
    }

  int mcnt = 0, ncnt = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      if (vst[i][j] == 0) {
        mcnt++;
        bfs(i, j, 0);
      }
    }

  memset(vst, 0, sizeof(vst));

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      if (vst[i][j] == 0) {
        ncnt++;
        bfs(i, j, 1);
      }
    }

  cout << mcnt << ' ' << ncnt;
}