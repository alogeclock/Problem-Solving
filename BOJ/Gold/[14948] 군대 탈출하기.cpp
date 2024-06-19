// idea: dijkstra, priority queue, 경로별 방문처리
// BFS 구현 시 경로 상 최소값·최대값을 유지하며 이동할 시 pq 고려
// debugging: jump로든 walk로든 한 번 방문했다면 재방문하지 않는다.
//  → dijkstra에서 정점의 첫 방문이 가장 빠른 경로임이 보장되기 때문

#include <bits/stdc++.h>
using namespace std;
#define VST_CUR vst[cur.row][cur.col][cur.jump]

int N, M;  // 행, 열
int m[101][101];
int vst[101][101][2];  // 걸어서 이동한 경우와 점프로 이동한 경우 구분
const int dr[] = {-1, 0, 1, 0}, dc[] = {0, -1, 0, 1};

struct Point {
 public:
  int row, col, level;
  bool jump;
  Point(int r, int c, int l, bool j) : row(r), col(c), level(l), jump(j){};
  bool operator>(const Point &x) const {
    // jump를 안 했을수록, 레벨이 작을수록
    return (level == x.level) ? jump > x.jump : level > x.level;
  }
};

int bfs() {
  priority_queue<Point, vector<Point>, greater<Point>> pq;
  fill(&vst[0][0][0], &vst[100][100][2], -1);

  pq.push(Point(0, 0, m[0][0], false));
  vst[0][0][0] = m[0][0];
  int minLevel = 1e9 + 1;

  while (pq.size()) {
    Point cur = pq.top();
    pq.pop();

    if (VST_CUR != -1 && VST_CUR < cur.level) continue;
    VST_CUR = cur.level;

    if (cur.row == N - 1 && cur.col == M - 1)
      return minLevel = min(cur.level, minLevel);

    for (int i = 0; i < 4; i++) {
      int nr = cur.row + dr[i], nc = cur.col + dc[i];
      if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
      // if (vst[nr][nc][cur.jump] != -1) continue; // 방문했다면 다시 이동 X

      int nl = max(cur.level, m[nr][nc]);
      pq.push(Point(nr, nc, nl, cur.jump));

      if (nl > cur.level && cur.jump == false) {
        nr += dr[i], nc += dc[i];  // 현재 진행방향대로 한 칸 더 이동
        if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
        // if (vst[nr][nc][cur.jump] != -1) continue; // 방문했다면 다시 이동 X

        nl = max(cur.level, m[nr][nc]);
        pq.push(Point(nr, nc, nl, true));
      }
    }
  }

  return minLevel;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> m[i][j];
    }
  }

  cout << bfs() << '\n';

  return 0;
}