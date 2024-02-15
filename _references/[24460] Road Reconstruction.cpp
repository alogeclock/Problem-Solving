// idea: BFS, matrix type dijkstra
// debugging: fill(), Point 연산자 오버로딩, dijkstra

#include <bits/stdc++.h>
using namespace std;

struct Point {
  int row, col, dist;
  Point(int r, int c, int w) : row(r), col(c), dist(w){};
};

bool operator>(const Point& x, const Point& y) { return x.dist > y.dist; }

int g[1001][1001];
int dist[1001][1001];
const int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, M;
  cin >> N >> M;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) cin >> g[i][j];

  fill(dist[0], dist[1001], 1e9);

  priority_queue<Point, vector<Point>, greater<Point>> dst;
  Point start(0, 0, g[0][0]);

  if (start.dist == -1) {
    cout << "-1\n";
    return 0;
  }

  dst.push(start);

  while (dst.size()) {
    Point cur = dst.top();
    dst.pop();

    if (cur.dist > dist[cur.row][cur.col]) continue;

    dist[cur.row][cur.col] = cur.dist;

    for (int i = 0; i < 4; i++) {
      int nr = cur.row + dr[i];
      int nc = cur.col + dc[i];
      int ndst = cur.dist + g[nr][nc];

      if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
      if (g[nr][nc] == -1) continue;

      if (dist[nr][nc] > ndst) {
        dist[nr][nc] = ndst;
        dst.push(Point(nr, nc, ndst));
      }
    }
  }

  if (dist[N - 1][M - 1] == 1e9)
    cout << "-1\n";
  else
    cout << dist[N - 1][M - 1];

  return 0;
}