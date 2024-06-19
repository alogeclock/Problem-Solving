#include <stdio.h>

int main() {
  long long sum = 0, num;
  for (int i = 0; i < 3; i++) {
    scanf("%lld", &num);
    sum += num;
  }
  printf("%lld", sum);
  return 0;
}