#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int set[21];

int main() {
  int T;
  scanf("%d", &T);

  while (T--) {
    char input[10];
    int val;

    scanf(" %s", input);

    if (!strcmp(input, "add")) {
      scanf("%d", &val);
      set[val] = 1;
    }
    if (!strcmp(input, "remove")) {
      scanf("%d", &val);
      set[val] = 0;
    }
    if (!strcmp(input, "check")) {
      scanf("%d", &val);
      if (set[val] == 1)
        printf("1\n");
      else
        printf("0\n");
    }
    if (!strcmp(input, "toggle")) {
      scanf("%d", &val);
      if (set[val] == 1)
        set[val] = 0;
      else
        set[val] = 1;
    }
    if (!strcmp(input, "all")) {
      for (int i = 1; i < 21; i++)
        set[i] = 1;
    }
    if (!strcmp(input, "empty")) {
      for (int i = 1; i < 21; i++)
        set[i] = 0;
    }
  }
  return 0;
}