// 좌표 정렬하기(퀵 정렬, compare 함수 사용법)

#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
  int x;
  int y;
} Point;

// compare()의 구성요소, *(type*) 값으로 할당
// A가 B보다 크면 1, 작으면 -1 반환(=오름차순 정렬)
int compare(const void* a, const void* b) {
  Point A = *(Point*)a;
  Point B = *(Point*)b;

  if (A.x > B.x)
    return 1;
  else if (A.x < B.x)
    return -1;
  else {
    if (A.y > B.y)
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