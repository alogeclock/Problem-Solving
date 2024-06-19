#include <stdio.h>

int main() {
  int num, H, W, N;

  scanf("%d", &num);

  while (num--) {
    scanf("%d %d %d", &H, &W, &N);
    W = ((N - 1) / H) + 1;
    if (N % H != 0) H = N % H;
    printf("%d%02d\n", H, W);
  }
}