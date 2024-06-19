#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int N, count, chk;
  char ps[51];
  scanf("%d", &N);

  while (N--) {
    count = 0;
    scanf("%s", ps);
    for (int i = 0; i < strlen(ps); i++) {
      if (ps[i] == '(')
        count++;
      else if (ps[i] == ')')
        count--;
      if (count < 0) {
        break;
      }
    }
    if (count == 0)
      printf("YES\n");
    else
      printf("NO\n");
  }

  return 0;
}