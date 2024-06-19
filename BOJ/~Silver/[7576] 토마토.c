// queue 기본 형태에 대한 공부가 부족해서 2시간을 고민

#include <stdio.h>
#include <string.h>
#define MAX_QUEUE_NUM 1000001
#define MAX_ROW_NUM 1001

typedef struct tomato {
  int row;
  int col;
} Tomato;

// direction_row, direction_col, 항상 상하좌우
const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int matrix[MAX_ROW_NUM][MAX_ROW_NUM];
int visited[MAX_ROW_NUM][MAX_ROW_NUM];
Tomato queue[MAX_QUEUE_NUM];

int tomato;
int ripe_tomato;
int front = -1, rear = -1;
int row, col;  // 행렬의 행의 수, 열의 수
int day = -1;

int main() {
  scanf("%d %d", &col, &row);

  // 토마토 상자 입력
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      scanf(" %d", &matrix[i][j]);

      if (matrix[i][j] != -1)
        tomato++;

      if (matrix[i][j] == 1) {
        rear++;
        visited[i][j] = 0;  // 방문 설정
        ripe_tomato++;      // 익힌 토마토 개수 증가

        queue[rear].row = i;
        queue[rear].col = j;
      }
    }
  }

  // 토마토 개수 = 익은 토마토 개수면 0 종료
  if (ripe_tomato == tomato) {
    printf("0\n");
    return 0;
  }

  // BFS를 통해 토마토 익히기 실행
  while (front < rear) {
    front++;
    int prev_day = visited[queue[front].row][queue[front].col];

    for (int i = 0; i < 4; i++) {
      int n_row = queue[front].row + dr[i];
      int n_col = queue[front].col + dc[i];

      // 좌표상 가지 못 할 경우 continue
      if (n_row < 0 || n_col < 0 || n_row >= row || n_col >= col) {
        continue;
      }

      // 이미 익은 토마토이거나, 벽인 경우를 제외
      if (matrix[n_row][n_col] == 0) {
        // 토마토 익히고 큐에 넣기
        rear++;
        ripe_tomato++;
        matrix[n_row][n_col] = 1;
        queue[rear].row = n_row;
        queue[rear].col = n_col;

        // visited 행렬 update + 가장 큰 날짜
        visited[n_row][n_col] = prev_day + 1;
        if (day < prev_day + 1) day = prev_day + 1;
      }
    }
  }

  // 익지 못한 토마토가 있으면 -1 종료
  if (ripe_tomato != tomato || ripe_tomato == 0) {
    printf("-1\n");
    return 0;
  }

  // 토마토가 익는 데 걸린 시간 출력
  printf("%d\n", day);

  return 0;
}