#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void hanoi_tower_small(int n, char from, char to, char aux) {
  if (n == 1) {
    printf("%c %c\n", from, to);
    return;
  }

  hanoi_tower_small(n - 1, from, aux, to);
  printf("%c %c\n", from, to);
  hanoi_tower_small(n - 1, aux, to, from);
}

int main() {
  int N;
  long long big = 0, small = 0;
  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    big *= 2;
    small = small * 2 + 1;
    big += small / 1000000000000000000;
    small %= 1000000000000000000;
  }

  if (big > 0)
    printf("%lld%lld\n", big, small);
  else
    printf("%lld\n", small);

  if (N <= 20) {
    hanoi_tower_small(N, '1', '3', '2');
  }

  return 0;
}
