#include <stdio.h>

int main() {
  int T;
  int apart[15][15];

  scanf("%d", &T);

  for (int i = 0; i < 15; i++) {
    for (int j = 1; j < 15; j++) {
      if (i == 0) {
        apart[i][j] = j;
        continue;
      }
      if (j == 1) {
        apart[i][j] = 1;
        continue;
      }
      apart[i][j] = apart[i][j - 1] + apart[i - 1][j];
    }
  }

  while (T--) {
    int floor, room;
    scanf("%d %d", &floor, &room);
    printf("%d\n", apart[floor][room]);
  }

  return 0;
}