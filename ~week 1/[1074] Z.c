// 배운 것: '1 << N' (2^n 표현), 4등분 판별(직접 방문 X)

#include <stdio.h>

int find_order(int N, int r, int c) {
  int order = 0;
  int size = 1 << N;

  while (size > 1) {
    size /= 2;

    // 4등분한 영역 중 어디에 해당하는지 판별
    int quadrant = (r >= size) * 2 + (c >= size);

    if (quadrant == 1) {  // 오른쪽 상단
      order += size * size;
      c -= size;
    } else if (quadrant == 2) {  // 왼쪽 하단
      order += size * size * 2;
      r -= size;
    } else if (quadrant == 3) {  // 오른쪽 하단
      order += size * size * 3;
      r -= size;
      c -= size;
    }
    // 왼쪽 상단에 있으면 추가 계산 없이 다음 단계로
  }

  return order;
}

int main() {
  int N, r, c;
  scanf("%d %d %d", &N, &r, &c);
  printf("%d\n", find_order(N, r, c));
  return 0;
}