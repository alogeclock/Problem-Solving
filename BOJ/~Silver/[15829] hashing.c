#include <math.h>
#include <stdio.h>

#define MAX_STR_LEN 51

int main() {
  int L;
  char c;
  long long hash = 0, r = 1;

  scanf("%d", &L);

  for (int i = 0; i < L; i++) {
    scanf(" %c", &c);
    hash = (hash + (c - 96) * r) % 1234567891;
    r = (r * 31) % 1234567891;
  }

  printf("%lld\n", hash);

  return 0;
}