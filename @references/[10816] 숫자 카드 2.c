// 무식하게 풀기
// 똑똑한 방법, 동적 할당 + 퀵 정렬 + 이진 탐색 (자주 나오는 방법)

#include <stdio.h>
#define MAX_ARRAY_NUMBER 20000001
#define MAX_CARDS_NUMBER 500001

int cards[MAX_ARRAY_NUMBER] = {0};
int answer[MAX_CARDS_NUMBER];

int main() {
  int N, M, i, cur;
  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    scanf("%d", &cur);
    cards[cur + 10000000]++;
  }

  scanf("%d", &M);
  for (i = 0; i < M; i++) {
    scanf("%d", &cur);
    answer[i] = cards[cur + 10000000];
  }

  for (i = 0; i < M; i++) {
    printf("%d ", answer[i]);
  }

  return 0;
}
