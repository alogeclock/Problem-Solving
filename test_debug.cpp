#include <stdio.h>

long mult2(long a, long b) {
  long s = a * b;
  return s;
}

void multstore(long *dest) {
  long t = mult2(5L, 3L);
  *dest = t;
}

int main() {
  long a, b, c;
  multstore(&a);
  printf("%d %d %d", a, b, c);
  return 0;
}