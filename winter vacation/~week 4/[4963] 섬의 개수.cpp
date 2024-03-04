#include <bits/stdc++.h>
using namespace std;

const int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1},
          dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int graph[51][51];
bool visited[51][51];
int w, h, cnt;

void bfs(int r, int c) {
  visited[r][c] = 1;
  for (int i = 0; i < 8; i++) {
    int row = dr[i] + r;
    int col = dc[i] + c;
    if (row < 0 || col < 0 || row >= h || col >= w) continue;
    if (!visited[row][col] && graph[row][col]) {
      bfs(row, col);
    }
  }
}

int main() {
  while (1) {
    cnt = 0;

    for (int i = 0; i < 51; i++) memset(visited[i], 0, sizeof(bool) * 51);

    scanf("%d %d", &w, &h);  // 너비(col), 높이(row)
    if (!w && !h) return 0;

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        scanf("%d", &graph[i][j]);
      }
    }

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (!visited[i][j] && graph[i][j]) {
          bfs(i, j);
          cnt++;
        }
      }
    }

    printf("%d\n", cnt);
  }
}
