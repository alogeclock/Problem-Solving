#include <stdio.h>

int main() {
  int N, K, a, b;
  scanf("%d %d", &N, &K);

  a = 1;
  b = 1;
  for (; K > 0;) {
    a *= N--;
    b *= K--;
  }

  printf("%d\n", a / b);
  return 0;
}