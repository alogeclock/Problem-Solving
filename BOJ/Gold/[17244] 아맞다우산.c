// idea: multiple bfs

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long

const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int dst[7][7], vst[55][55], m[55][55], bvst[7];
int item, dot_pos[7][2];
int q[10100][3], front, back;
int N, M;

int backtracking(int k, int sum) {
  int flag = 0, ret = 0x3f3f3f3f;
  bvst[k] = 1;
  for (int i = 1; i < 6; i++) {
    if (bvst[i] == 1) continue;
    flag = 1;
    int temp = backtracking(i, sum + dst[k][i]);
    if (ret > temp) ret = temp;
  }
  bvst[k] = 0;
  if (!flag) return sum + dst[k][6];
  return ret;
}

int bfs(int sr, int sc, int dr, int dc) {
  int dist = 0x3f3f3f3f;
  memset(vst, 0x3f, sizeof(vst));
  q[0][0] = sr, q[0][1] = sc, q[0][2] = 0;
  front = 0, back = 1, vst[sr][sc] = 0;

  while (front < back) {
    int cr = q[front][0], cc = q[front][1], cdst = q[front][2];
    front++;
    if (cr == dr && cc == dc && dist > cdst) dist = cdst;

    for (int i = 0; i < 4; i++) {
      int nr = cr + dx[i], nc = cc + dy[i], ndst = cdst + 1;
      if (nr < 0 || nr >= M || nc < 0 || nc >= N) continue;
      if (vst[nr][nc] <= ndst || m[nr][nc] == 1) continue;

      q[back][0] = nr, q[back][1] = nc, q[back][2] = ndst;
      vst[nr][nc] = ndst;
      back++;
    }
  }

  return dist;
}

int main() {
  scanf(" %d %d", &N, &M);

  for (int r = 0; r < M; r++) {
    for (int c = 0; c < N; c++) {
      char input;
      scanf(" %c", &input);
      if (input == '#') m[r][c] = 1;
      if (input == 'S') dot_pos[0][0] = r, dot_pos[0][1] = c;
      if (input == 'E') dot_pos[6][0] = r, dot_pos[6][1] = c;
      if (input == 'X') {
        item++;
        dot_pos[item][0] = r, dot_pos[item][1] = c;
      }
    }
  }

  for (int s = 0; s <= item; s++) { // 시작점, 각 item에서 bfs 시작
    // 각 item에서 bfs 종료
    int sr = dot_pos[s][0], sc = dot_pos[s][1]; // start
    for (int e = 1; e <= item; e++) {
      dst[s][e] = bfs(sr, sc, dot_pos[e][0], dot_pos[e][1]);
      dst[e][s] = dst[s][e];
    }

    // 종점에서 bfs 종료
    dst[s][6] = bfs(sr, sc, dot_pos[6][0], dot_pos[6][1]);
    dst[6][s] = dst[s][6];
  }

  bvst[0] = 1;
  for (int i = item + 1; i < 6; i++)
    bvst[i] = 1;
  printf("%d\n", backtracking(0, 0));
  return 0;
}