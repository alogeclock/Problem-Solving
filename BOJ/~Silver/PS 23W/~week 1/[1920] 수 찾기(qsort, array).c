// 퀵 정렬, 이분 탐색

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 100001

int input[MAX_ELEMENTS];
bool answer[MAX_ELEMENTS];

// qsort 기준 함수
int compare(const void* a, const void* b) {
  int num1 = *(int*)a;
  int num2 = *(int*)b;

  if (num1 > num2)
    return 1;
  else if (num1 < num2)
    return -1;
  else
    return 0;
}

bool binSearch(int min, int max, int target) {
  int mid = (min + max) / 2;

  if (min > max) return 0;

  if (target > input[mid])
    binSearch(mid + 1, max, target);
  else if (target < input[mid])
    binSearch(min, mid - 1, target);
  else
    return 1;
}

int main() {
  int N, M, val, i;

  // 입력 후 qsort 정렬
  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    scanf("%d", &input[i]);
  }
  qsort(input, N, sizeof(int), compare);

  scanf("%d", &M);

  // 이진 탐색
  for (i = 0; i < M; i++) {
    scanf("%d", &val);
    answer[i] = binSearch(0, N - 1, val);
  }

  for (i = 0; i < M; i++) {
    printf("%d\n", answer[i]);
  }

  return 0;
}