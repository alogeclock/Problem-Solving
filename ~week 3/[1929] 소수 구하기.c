#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 1001

int prime[MAX_NUM];

int main() {
  int N, M;
  scanf("%d %d", &N, &M);

  int top = 1;
  prime[0] = 2;

  // 1000까지의 소수 설정
  for (int i = 2; i < 1000; i++) {
    int chk = 1;
    for (int j = 0; j < top; j++) {
      if (i % prime[j] == 0) {
        chk = 0;
        break;
      }
    }
    if (chk == 1) {
      prime[top++] = i;
    }
  }

  for (int i = N; i <= M; i++) {
    int chk = 1;
    for (int j = 0; j < top && prime[j] < i; j++) {
      if (i % prime[j] == 0) {
        chk = 0;
        break;
      }
    }
    if (chk == 1 && i > 1) printf("%d\n", i);
  }

  return 0;
}