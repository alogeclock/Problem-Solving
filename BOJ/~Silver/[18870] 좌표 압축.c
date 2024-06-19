#include <stdio.h>
#include <stdlib.h>

typedef struct _point {
  int value;
  int idx;
} point;

int compare(const void* a, const void* b) {
  point A = *(point*)a;
  point B = *(point*)b;

  if (A.value > B.value) {
    return 1;
  } else {
    return -1;
  }
}

int main(void) {
  int n;
  scanf("%d", &n);

  point points[n];

  for (int i = 0; i < n; i++) {
    scanf("%d", &points[i].value);
    points[i].idx = i;
  }

  qsort(points, n, sizeof(point), compare);

  int result[n];
  int cnt = 0;
  int max = points[0].value;
  for (int i = 0; i < n; i++) {
    if (points[i].value != max) {
      max = points[i].value;
      cnt++;
    }

    result[points[i].idx] = cnt;
  }

  for (int i = 0; i < n; i++) {
    printf("%d ", result[i]);
  }
}
