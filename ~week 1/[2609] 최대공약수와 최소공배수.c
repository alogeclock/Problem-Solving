#include <stdio.h>

int main() {
  int a, b, remain;
  scanf("%d %d", &a, &b);

  int lcm = a * b;  // <= 10000이므로 곱하기 가능
  if (a < b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
  }

  while (1) {  // remain이 0이면 종료
    remain = a % b;
    if (remain == 0) break;
    a = b;
    b = remain;
  }

  printf("%d\n", b);
  printf("%d\n", lcm / b);
}