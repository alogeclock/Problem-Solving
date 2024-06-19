// idea: dynamic programming

#include <stdio.h>

int main() {
  int X, cal[1000001];
  scanf("%d", &X);

  cal[2] = 1;
  cal[3] = 1;

  for (int i = 4; i <= X; i++) {
    int a = cal[i - 1] + 1;
    if (i % 2 == 0 && a > cal[i / 2] + 1)
      a = cal[i / 2] + 1;
    if (i % 3 == 0 && a > cal[i / 3] + 1)
      a = cal[i / 3] + 1;
    cal[i] = a;
  }

  printf("%d\n", cal[X]);

  return 0;
}