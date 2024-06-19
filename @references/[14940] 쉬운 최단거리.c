// idea: shortest-path, BFS, queue, dynamic allocation

// 동적 할당으로 입력받아 풀어보기
// shortest-path algorithms(dijkstra, BFS)

// debugging: 동적 할당 시에 sizeof(int)로 착각
// y, x 순서라는 점 기억, front, rear 관리법 기억

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1

typedef struct point {
  int x;
  int y;
} Point;

const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};  // 상우하좌
int row, col;
Point goal;
Point *queue;

void find_path(int **map, int **visited, int x, int y);

int main() {
  static int **map;
  static int **visited;
  scanf("%d %d", &row, &col);

  // 메모리 동적 할당
  map = (int **)malloc(sizeof(int *) * row);
  visited = (int **)calloc(row, sizeof(int *));
  for (int i = 0; i < row; i++) {
    map[i] = (int *)malloc(sizeof(int) * col);
    visited[i] = (int *)calloc(col, sizeof(int));
  }

  // 지도 입력 (목표 지점 입력)
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      scanf("%d", &map[i][j]);
      if (map[i][j] == 2) {
        goal.y = i;
        goal.x = j;
      }
    }
  }

  // 경로 탐색
  find_path(map, visited, goal.x, goal.y);

  // 갈 수 있는 곳인데 방문하지 않은 경우 -1 입력
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (!visited[i][j] && map[i][j] == 1) {
        visited[i][j] = -1;
      }
      printf("%d ", visited[i][j]);
    }
    printf("\n");
  }

  // 메모리 할당 해제
  for (int i = 0; i < row; i++) {
    free(map[i]);
    free(visited[i]);
  }

  free(map);
  free(visited);

  return 0;
}

void find_path(int **map, int **visited, int x, int y) {
  // 1차원 배열 동적 할당
  queue = (Point *)malloc(row * col * sizeof(Point));
  int nx, ny;
  int front = -1, rear = 0;

  queue[rear].x = x;
  queue[rear].y = y;

  while (front < rear) {
    front++;
    int path_len = visited[queue[front].y][queue[front].x];

    for (int i = 0; i < 4; i++) {
      nx = queue[front].x + dx[i];
      ny = queue[front].y + dy[i];

      // 좌표상 갈 수 없는 경우 continue
      if (nx < 0 || ny < 0 || nx >= col || ny >= row) continue;

      // 지도상 갈 수 있으면서 방문하지 않은 경우
      if (!visited[ny][nx] && map[ny][nx] == 1) {
        rear++;
        queue[rear].x = nx;
        queue[rear].y = ny;
        visited[ny][nx] = path_len + 1;
      }
    }
  }

  free(queue);
}
