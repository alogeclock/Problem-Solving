#include <stdio.h>
int main() {
  int M, N;
  scanf("%d %d", &M, &N);

  if (M <= N) {
    printf("%d\n", 2 * (M - 1));
  } else {
    printf("%d\n", 2 * (M - 1) - 2 * (M - N - 1) - 1);
  }

  return 0;
}