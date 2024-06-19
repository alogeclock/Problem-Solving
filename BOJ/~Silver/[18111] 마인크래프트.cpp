#include <bits/stdc++.h>
#define MAX_ROW 501
using namespace std;

int matrix[MAX_ROW][MAX_ROW];
int min_time[257];
int result;

int main() {
  int N, M, B;
  scanf("%d %d %d", &N, &M, &B);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) {
      scanf("%d", &matrix[i][j]);
      B += matrix[i][j];
    }

  // 가능한 높이 brute-force 탐색
  int possibleHeight = (256 < B / (N * M)) ? 256 : B / (N * M);
  for (int i = 0; i <= possibleHeight; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < M; k++) {
        if (matrix[j][k] > i) {
          min_time[i] += 2 * (matrix[j][k] - i);
        } else
          min_time[i] += i - matrix[j][k];
      }
    }
    result = (min_time[result] >= min_time[i]) ? i : result;
  }

  // 같은 최소시간을 갖는 경우 높이가 높은 것 선택
  for (int i = possibleHeight; i >= 0; i--) {
    if (min_time[result] == min_time[i]) {
      printf("%d %d\n", min_time[result], result);
      break;
    }
  }

  return 0;
}
