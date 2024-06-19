#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define PINF 1000000007

bool m[105][105];
int vst[105][105];
const int dr[] = {-1, 0, 1, 0}, dc[] = {0, -1, 0, 1};

struct Point {
  int row, col, dst;
  Point(int r, int c, int d) : row(r), col(c), dst(d) {} 
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N, M; // row, column
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < M; j++) m[i][j] = s[j] - 48;
  }

  memset(vst, 0x3f, sizeof(vst));

  queue<Point> q;
  q.push(Point(0, 0, 1)); // 시작 위치 입력
  while (q.size()) {
    auto [cr, cc, cdst] = q.front();
    q.pop();

    if (vst[cr][cc] < cdst) continue;
    if (cr < 0 || cc < 0 || cr >= N || cc >= M) continue;

    for (int i = 0; i < 4; i++) {
      int nr = cr + dr[i], nc = cc + dc[i];
      int ndst = cdst + 1;
      
      if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
      if (ndst < vst[nr][nc] && m[nr][nc]) { // 이동 가능한 칸이고 거리가 짧음
        vst[nr][nc] = ndst;
        q.push(Point(nr, nc, ndst));
      }
    }
  }
  
  cout << vst[N - 1][M - 1];
}