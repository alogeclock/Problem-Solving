// O(n^2) = 2500이므로 계산이 많이 요구되지 않음

#include <stdio.h>
#include <string.h>
#define MAX_ROW_NUMBER 51

int row, column, worms;  // 전역 변수로 설정
int field[MAX_ROW_NUMBER][MAX_ROW_NUMBER] = {0};

void DFS(int x, int y) {
  field[x][y] = -1;  // 이미 온 곳을 표시
  if (x > 0 && field[x - 1][y] == 1) DFS(x - 1, y);
  if (x < (row - 1) && field[x + 1][y] == 1) DFS(x + 1, y);
  if (y < (column - 1) && field[x][y + 1] == 1) DFS(x, y + 1);
  if (y > 0 && field[x][y - 1] == 1) DFS(x, y - 1);
}

int calculate_worms() {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
      if (field[i][j] == 1) {
        DFS(i, j);
        worms++;
      }
    }
  }
  return worms;
}

int main() {
  int T;
  int cabbage_num;
  int x, y;

  scanf("%d", &T);

  while (T--) {
    memset(field, 0, sizeof(field));
    worms = 0;
    scanf("%d %d %d", &row, &column, &cabbage_num);
    for (int i = 0; i < cabbage_num; i++) {
      scanf("%d %d", &x, &y);
      field[x][y] = 1;
    }

    printf("%d\n", calculate_worms());
  }

  return 0;
}