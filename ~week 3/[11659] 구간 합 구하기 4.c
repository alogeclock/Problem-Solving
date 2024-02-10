// sum 배열, 1000 * 100000일 경우 10^3 * 10^5
// 10^8 = 1억이므로 int 자료형에 입력 가능

#include <stdio.h>
#define MAX_NUM 100001

int arr[MAX_NUM];
int sum[MAX_NUM];

int main() {
  // 입력되는 수의 개수, 합을 구해야 하는 회수
  int N, M;
  scanf("%d %d", &N, &M);

  for (int i = 1; i <= N; i++) {
    scanf("%d", &arr[i]);
    if (i == 1)
      sum[i] = arr[i];
    else
      sum[i] = sum[i - 1] + arr[i];
  }

  while (M--) {
    int start, end, res;
    scanf("%d %d", &start, &end);
    res = sum[end] - sum[start] + arr[start];

    printf("%d\n", res);
  }
  return 0;
}