// idea: dijkstra, timeAfterFoundGram
// remind: 다익스트라는 한 정점에서 다른 모든 정점의 최단거리를 구함
// debugging: 탐색 중에 거리를 저장하고 비교하지 않고, 탐색이 끝난 뒤 비교
// 이미 N, M에 익숙해졌다. R, C 저장보단 그냥 N, M 저장이 나을 듯.

#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define PINF 1000000007

int m[105][105], dst[105][105];
const int dr[] = {0, 1, 0, -1}, dc[] = {1, 0, -1, 0};
struct Point {
  int dst, row, col;
  Point(int d, int r, int c) : dst(d), row(r), col(c) {}
  bool operator>(const Point& x) const { return dst > x.dst; }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int R, C, T;  // row, col, time
  cin >> R >> C >> T;
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      cin >> m[r][c];
    }
  }

  // 그람을 찾은 뒤 공주를 구하기까지의 소요시간
  priority_queue<Point, vector<Point>, greater<Point>> pq;
  // 그람을 찾는 데 소요되는 시간을 dijkstra로 찾고 더하기 vs. 직접 가기

  int ans = INF;
  memset(dst, INF, sizeof(dst));
  dst[0][0] = 0;
  pq.push(Point(0, 0, 0));

  // 목적지에 직접 이동
  while (pq.size()) {
    auto [hdst, cr, cc] = pq.top();
    pq.pop();

    if (cr < 0 || cc < 0 || cr >= R || cc >= C) continue;
    if (dst[cr][cc] < hdst) continue;  // 거리가 더 길면 무시
    if (cr == R - 1 && cc == C - 1) break;

    for (int i = 0; i < 4; i++) {
      int ndst = hdst + 1, nr = cr + dr[i], nc = cc + dc[i];
      if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
      if (dst[nr][nc] > ndst && m[nr][nc] != 1) {
        dst[nr][nc] = ndst;
        pq.push(Point(ndst, nr, nc));
      }
    }
  }

  for (int r = 0; r < R; r++)
    for (int c = 0; c < C; c++)
      if (m[r][c] == 2) {
        int timeAfterFoundGram = (R + C) - (r + c) - 2;
        ans = min(ans, dst[r][c] + timeAfterFoundGram);
      }

  ans = min(ans, dst[R - 1][C - 1]);

  (ans > T) ? cout << "Fail" : cout << ans;
}