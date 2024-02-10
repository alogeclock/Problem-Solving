#include <stdio.h>

int main() {
  int a[3];
  int max = 0;
  int same = 0;
  int d_idx, idx;
  for (int i = 0; i < 3; i++) {
    scanf("%d", &a[i]);
    if (a[i] > max) max = a[i];
  }

  // 3 °°
  if (a[0] == a[1] && a[1] == a[2]) {
    printf("%d", a[0] * 1000 + 10000);
    return 0;
  }

  // 3 ´Ù
  if (a[0] != a[1] && a[1] != a[2] && a[2] != a[0]) {
    printf("%d", max * 100);
    return 0;
  }

  for (int i = 0; i < 3; i++) {
    if (a[i] == max) {
      same++;
      idx = i;
    } else
      d_idx = i;
  }

  if (same == 2)
    printf("%d\n", a[idx] * 100 + 1000);
  else
    printf("%d\n", a[d_idx] * 100 + 1000);

  return 0;
}