#include <stdio.h>

int main() {
  int N, M;
  int arr[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  int last = 0;
  scanf("%d %d", &N, &M);

  int idx = M;

  while (!last) {
    // arr[idx]가 해당 idx의 끝에 도달했는지 확인하며 idx 이동
    while (arr[idx] == N - (M - idx) && idx > 1) {
      idx--;
    }

    // arr[1]부터 arr[3]까지 출력
    for (int i = 1; i <= M; i++) {
      printf("%d ", arr[i]);
    }
    printf("\n");

    if (arr[1] == N - M + 1) last = 1;

    // 가리키는 위치를 변화시켜 가면서 새로운 수열 탐색
    arr[idx]++;

    // idx가 이동했다면 규칙에 따라 초기화
    if (idx != M) {
      for (int j = idx + 1; j <= M; j++) {
        arr[j] = arr[j - 1] + 1;
      }
      idx = M;
    }
  }

  return 0;
}