#include <stdio.h>

int main() {
  int n, p = 2, sum = 2;
  scanf("%d", &n);
  if (n == 1) sum--;
  while (n > 2) {
    if (n % 2 == 0) sum += p;
    n -= n / 2;
    p *= 2;
  }
  printf("%d", sum);
}