#include <stdio.h>

int main() {
  int T, N;
  int x, y, z;
  scanf("%d", &T);

  while (T--) {
    scanf("%d", &N);

    if (N == 0) {
      printf("1 0\n");
      continue;
    }
    if (N == 1) {
      printf("0 1\n");
      continue;
    }

    x = 1;
    y = 1;
    for (int i = 2; i < N; i++) {
      z = x + y;
      x = y;
      y = z;
    }
    printf("%d %d\n", x, y);
  }

  return 0;
}