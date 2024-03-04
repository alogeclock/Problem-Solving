#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char A[10], B[10];
  char min_A[10], max_A[10];
  char min_B[10], max_B[10];
  int min, max;

  scanf("%s %s", A, B);

  strcpy(min_A, A);
  strcpy(max_A, A);
  strcpy(min_B, B);
  strcpy(max_B, B);

  for (int i = 0; i < 10; i++) {
    if (A[i] == '5')
      max_A[i] = '6';
    if (A[i] == '6')
      min_A[i] = '5';
    if (B[i] == '5')
      max_B[i] = '6';
    if (B[i] == '6')
      min_B[i] = '5';
  }

  min = atoi(min_A) + atoi(min_B);
  max = atoi(max_A) + atoi(max_B);

  printf("%d %d", min, max);

  return 0;
}