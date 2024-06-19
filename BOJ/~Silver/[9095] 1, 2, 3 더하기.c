#include <stdio.h>

int array[10] = {1, 2, 4, 7, 13, 24, 44, 81, 149, 274};

int main() {
  int T;
  scanf("%d", &T);

  while (T--) {
    int target;
    scanf("%d", &target);
    printf("%d\n", array[target-1]);
  }

  return 0;
}