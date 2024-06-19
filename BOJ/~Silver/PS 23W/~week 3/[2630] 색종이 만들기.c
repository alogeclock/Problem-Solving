// idea: recursive method

#include <stdio.h>
#define MAX_NUM 128

const int d_row[4] = {0, 1, 0, 1};
const int d_col[4] = {0, 0, 1, 1};
int map[MAX_NUM][MAX_NUM];
int white, blue;  // 흰색 0, 파란색 1

int cut(int row, int col, int len) {
  // 나누기
  if (len == 1) {
    if (map[row][col] == 1)
      blue++;
    else
      white++;
    return map[row][col];
  }
  // 영역을 4등분

  len /= 2;
  int area[4], sum = 0, same = 1;
  for (int i = 0; i < 4; i++) {
    area[i] = cut(row + d_row[i] * len, col + d_col[i] * len, len);
    if (area[i] != -1)
      sum += area[i];
    else
      same = 0;
  }

  // 합치기
  // 전부 파랑
  if (same && sum == 4) {
    blue -= 3;
    return 1;
  }
  // 전부 하양
  if (same && sum == 0) {
    white -= 3;
    return 0;
  }

  else
    return -1;
}

int main() {
  int N;
  scanf("%d", &N);

  // 지도 입력
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &map[i][j]);
    }
  }

  cut(0, 0, N);

  printf("%d\n%d\n", white, blue);

  return 0;
}