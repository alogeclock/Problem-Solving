// idea: dp, 계산하면서 계속 %10007로 나눠 주는 연산(모듈로 연산)

#include <stdio.h>
#define MAX_NUM 1001

int main() {
  int N;
  scanf("%d", &N);

  int x, y, z, i;

  x = 1;
  y = 2;
  z = 3;

  for (i = 1; i < N; i++) {
    z = x + y;
    x = y % 10007;
    y = z % 10007;
  }

  printf("%d\n", x);

  return 0;
}