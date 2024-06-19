#include <stdio.h>

int main() {
  int arr[3], max, temp;
  while (1) {
    max = 0;
    for (int i = 0; i < 3; i++) {
      scanf("%d", &arr[i]);
      if (arr[0] == 0) return 0;  // 프로그램 종료
      if (i > 0 && arr[i] < arr[i - 1]) {
        temp = arr[i - 1];
        arr[i - 1] = arr[i];
        arr[i] = temp;
      }
    }
    if (arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2]) {
      printf("right\n");
    } else
      printf("wrong\n");
  }
}