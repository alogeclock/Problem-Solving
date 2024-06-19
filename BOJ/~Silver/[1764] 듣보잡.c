// idea: 문자열의 이분 탐색을 통해 교집합 탐색

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUM 500001

typedef struct _name {
  char name[21];
} Name;

Name cannot_hear[MAX_NUM], cannot_see[MAX_NUM];  // 교집합 탐색
Name cannot_hear_and_see[MAX_NUM];
int top = 0;

int compare(const void *a, const void *b) {
  Name A = *(Name *)a;
  Name B = *(Name *)b;

  if (strcmp(A.name, B.name) > 0)
    return 1;
  else
    return -1;
}

int main() {
  int N, M;
  int i;
  scanf("%d %d", &N, &M);

  for (i = 0; i < N; i++) {
    scanf("%s", cannot_hear[i].name);
  }

  for (i = 0; i < M; i++) {
    scanf("%s", cannot_see[i].name);
  }

  qsort(cannot_hear, N, sizeof(Name), compare);
  qsort(cannot_see, M, sizeof(Name), compare);

  for (i = 0; i < N; i++) {
    int left, right, mid;
    left = 0, right = M - 1;

    while (left <= right) {
      mid = (left + right) / 2;
      // strcmp(찾으려는 값, 찾는 배열)
      int cmp = strcmp(cannot_hear[i].name, cannot_see[mid].name);

      if (cmp == 0) {
        cannot_hear_and_see[top++] = cannot_hear[i];
        break;
      } else if (cmp > 0)
        left = mid + 1;
      else
        right = mid - 1;
    }
  }

  printf("%d\n", top);
  for (i = 0; i < top; i++) {
    printf("%s\n", cannot_hear_and_see[i].name);
  }

  return 0;
}