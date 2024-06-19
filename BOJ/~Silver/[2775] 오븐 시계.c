#include <stdio.h>

int main() {
  int hour, min, elapsed;
  scanf("%d %d %d", &hour, &min, &elapsed);

  while (elapsed + min >= 60) {
    hour++;
    if (hour == 24) hour = 0;
    elapsed -= 60;
  }

  printf("%d %d", hour, min + elapsed);

  return 0;
}