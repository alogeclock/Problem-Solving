// idea: top-down dp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long

// direction_row, direction_col
const int dr[] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dc[] = {2, 1, -1, -2, -2, -1, 1, 2};

// board[k][r][c]: K번째 이동 시 각 정점에 도착할 확률
double board[55][55][55];

int main() {
  int N, row, col, K;
  scanf(" %d %d %d %d", &N, &row, &col, &K);
  board[0][row - 1][col - 1] = 1.0; // 시작지점 방문 여부, 확률 초기화

  for (int k = 1; k <= K; k++) {
    for (int r = 0; r < N; r++) {
      for (int c = 0; c < N; c++) { // 모든 정점에 대해 이동 계산
        if (board[k - 1][r][c] == 0) continue;

        for (int i = 0; i < 8; i++) {
          int nr = r + dr[i], nc = c + dc[i];
          if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
          board[k][nr][nc] += board[k - 1][r][c] / 8.0;
        }
      }
    }
  }

  double sum = 0;
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      sum += board[K][r][c];
    }
  }

  printf("%.30lf\n", sum);

  return 0;
}