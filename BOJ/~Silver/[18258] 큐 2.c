#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long

int queue[2002000];
int front, back;

int main() {
  int T;
  scanf(" %d", &T);
  const char *string[5] = {"pop", "size", "empty", "front", "back"};

  while (T--) {
    char input[100];
    scanf(" %s", &input);

    if (!strcmp(input, "push")) {
      int X;
      scanf(" %d", &X);
      queue[back++] = X;
      continue;
    }

    for (int i = 0; i < 5; i++) {
      if (!strcmp(input, string[i])) {
        switch (i) {
        case 0: // pop
          if (front == back)
            printf("-1\n");
          else
            printf("%d\n", queue[front++]);
          break;

        case 1: // size
          printf("%d\n", back - front);
          break;

        case 2:
          (front == back) ? printf("%d\n", 1) : printf("%d\n", 0);
          break;

        case 3:
          (front == back) ? printf("-1\n") : printf("%d\n", queue[front]);
          break;

        case 4: // back
          (front == back) ? printf("-1\n") : printf("%d\n", queue[back - 1]);
          break;
        }
      }
    }
  }
  return 0;
}