#include <stdio.h>
#include <stdlib.h>
#define MAX_USERS 1001

int time[MAX_USERS];

int compare(const void *a, const void *b) {
  int A = *(int *)a;
  int B = *(int *)b;

  if (A > B)
    return 1;
  else
    return -1;
}

int main() {
  long long sum = 0;
  int elapsed_time = 0;
  int user;

  scanf("%d", &user);

  for (int i = 0; i < user; i++) {
    scanf("%d", &time[i]);
  }

  qsort(time, user, sizeof(int), compare);

  for (int i = 0; i < user; i++) {
    elapsed_time += time[i];
    sum += elapsed_time;
  }

  printf("%lld", sum);

  return 0;
}