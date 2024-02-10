
#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
  int x;
  int y;
} Point;

int compare(const void* a, const void* b) {
  Point A = *(Point*)a;
  Point B = *(Point*)b;

  if (A.y > B.y)
    return 1;
  else if (A.y < B.y)
    return -1;
  else {
    if (A.x > B.x)
      return 1;
    else
      return -1;
  }
}

int main() {
  int N;
  Point* point;

  scanf("%d", &N);
  point = (Point*)malloc(sizeof(Point) * N);

  for (int i = 0; i < N; i++)
    scanf("%d %d", &point[i].x, &point[i].y);

  qsort(point, N, sizeof(Point), compare);

  for (int i = 0; i < N; i++)
    printf("%d %d\n", point[i].x, point[i].y);

  return 0;
}