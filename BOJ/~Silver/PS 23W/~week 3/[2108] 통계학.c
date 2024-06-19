// idea: 출력값 다루기, 퀵 정렬

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 500001

typedef struct duplicate {
  int val;
  int times;
} Duplicate;

int stat[MAX_NUM];
// 중복된 좌표의 idx와, 중복 회수 기록
Duplicate duplicate[10001];

int compare(const void *a, const void *b) {
  int A = *(int *)a;
  int B = *(int *)b;

  if (A > B)
    return 1;
  else
    return -1;
}

int compare_dup(const void *a, const void *b) {
  Duplicate A = *(Duplicate *)a;
  Duplicate B = *(Duplicate *)b;

  if (A.times < B.times)
    return 1;
  else if (A.times > B.times)
    return -1;

  else {
    if (A.val > B.val)
      return 1;
    else
      return -1;
  }
}

int main() {
  int N;
  scanf("%d", &N);

  int sum = 0, min = 10000, max = -10000;
  for (int i = 0; i < N; i++) {
    scanf("%d", &stat[i]);
    if (min > stat[i]) min = stat[i];
    if (max < stat[i]) max = stat[i];
    sum += stat[i];
  }

  qsort(stat, N, sizeof(int), compare);

  int j = 0;
  for (int i = 0; i < N; i++) {
    if (i == 0) {
      duplicate[0].val = stat[0];
      duplicate[0].times++;
      continue;
    }
    if (i > 0 && stat[i - 1] != stat[i]) {
      duplicate[++j].val = stat[i];
    }
    duplicate[j].times++;
  }

  qsort(duplicate, j + 1, sizeof(Duplicate), compare_dup);

  if (sum > 0)
    printf("%d\n", (int)((double)sum / N + 0.5));  // 산술평균
  else
    printf("%d\n", (int)((double)sum / N - 0.5));

  printf("%d\n", stat[N / 2]);  // 중앙값

  if (j > 0 && duplicate[0].times == duplicate[1].times)
    printf("%d\n", duplicate[1].val);  // 최빈값 중 두 번째로 작은 값
  else
    printf("%d\n", duplicate[0].val);

  printf("%d\n", max - min);  // 범위

  return 0;
}