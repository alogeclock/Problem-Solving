// idea: 수학적 조건 찾기

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUM 1000001

int main() {
  int N, len;
  char num[10];
  scanf("%d", &N);

  sprintf(num, "%d", N);
  len = strlen(num);

  // 분해합 크기에 따라 최대 가능한 후보군 계산(N - 9 * 자릿수)
  int constructor = MAX_NUM;
  for (int i = N; i >= N - len * 9 && i > 0; i--) {
    sprintf(num, "%d", i);
    int constructor_len = strlen(num);

    // 현재 분해합의 자릿수를 계산하고, N과 동일한지 확인
    int sum = 0;
    for (int j = 0; j < constructor_len; j++) {
      sum += ((int)num[j] - 48);
    }

    if (i + sum == N & i < constructor)
      constructor = i;
  }

  if (constructor == MAX_NUM)
    printf("0\n");
  else
    printf("%d\n", constructor);

  return 0;
}
