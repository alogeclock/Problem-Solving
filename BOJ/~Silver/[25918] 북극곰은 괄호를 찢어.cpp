#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long

char str[200200];
int stack[200200];
int top = 0;

int main() {
  int N;
  scanf(" %d", &N);
  scanf(" %s", str);
  int len = strlen(str), day = 0;

  for (int i = 0; i < len; i++) {
    if (top > 0 && stack[top - 1] != str[i]) top--;
    else stack[top++] = str[i];
    if (top > day) day = top;
  }

  if (top > 0) printf("-1\n");
  else printf("%d\n", day);
}