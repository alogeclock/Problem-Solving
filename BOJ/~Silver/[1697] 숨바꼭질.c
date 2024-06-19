#include <stdio.h>
#define MAX_NUM 100001

// 0 ~ 100000까지 존재
int time[MAX_NUM];

int main() {
  int subin, brother;
  scanf("%d %d", &subin, &brother);

  for (int i = 0; i < MAX_NUM; i++) {
    time[i] = MAX_NUM;
  }

  for (int i = 0; i <= subin; i++) {
    time[subin - i] = i;
  }

  for (int i = 0; i < MAX_NUM; i++) {
    int temp = time[i] + 1;

    if (2 * i < MAX_NUM && time[2 * i] > temp)
      time[2 * i] = temp;

    if (i < MAX_NUM - 1 && time[i + 1] > temp)
      time[i + 1] = temp;

    if (i > 0 && time[i - 1] > temp) {
      time[i - 1] = temp;
      i -= 2;
    }
  }
  printf("%d\n", time[brother]);
}