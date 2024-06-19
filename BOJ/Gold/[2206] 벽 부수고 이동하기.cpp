#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF ((int)1e9 + 7)
#define ll long long

bool matrix[1005][1005];
int vst[1005][1005][2]; // 이동한 거리를 저장
const int dr[] = {-1, 0, 1, 0}, dc[] = {0, -1, 0, 1};

struct Point {
  int len, row, col;
  bool wall;
  Point(int l, int r, int c, bool w) : len(l), row(r), col(c), wall(w) {}
  bool operator>(const Point &x) const {
    return len > x.len;
  } // 거리가 작을수록
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N, M;
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    for (int j = 0; s[j]; j++)
      matrix[i][j] = (s[j] == '1') ? true : false;
    cin.clear();
  }

  memset(vst, 0x3f, sizeof(vst));
  priority_queue<Point, vector<Point>, greater<Point>> pq; // 거리 기준 pq
  pq.push(Point(1, 0, 0, 1));
  vst[0][0][1] = 1;

  while (pq.size()) {
    // cr: cur_row, cc: cur_col, cw: cur_wall
    auto [hdst, cr, cc, cw] = pq.top();
    pq.pop();

    if (cr < 0 || cc < 0 || cr >= N || cc >= M) continue;
    if (hdst > vst[cr][cc][cw]) continue;
    if (cr == N - 1 && cc == M - 1) break; // 도착지에 가장 먼저 도착한 경우

    for (int i = 0; i < 4; i++) {
      int nr = cr + dr[i], nc = cc + dc[i];
      int ndst = hdst + 1;

      if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;

      if (matrix[nr][nc]) { // 벽에 막혀 있다면
        if (!cw || ndst > vst[nr][nc][0]) continue;
        // 부술 수 없거나, 이동 거리가 더 길다면 continue;
        vst[nr][nc][0] = ndst;
        pq.push(Point(ndst, nr, nc, 0));
      } else if (ndst < vst[nr][nc][cw]) { // 이동 거리가 더 길다면 continue;
        vst[nr][nc][cw] = ndst;
        pq.push(Point(ndst, nr, nc, cw));
      }
    }
  }

  int ans = min(vst[N - 1][M - 1][0], vst[N - 1][M - 1][1]);
  ans = (ans == INF) ? -1 : ans;
  cout << ans;
}