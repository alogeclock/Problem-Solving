#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN_NUMBER 10001

int havingLAN[MAX_LEN_NUMBER];
int num;  // 가진 랜선의 개수

int binSearch(long long min, long long max, int target);
int lanNum(long long mid);

int main() {
  int neededLAN, minlen, maxlen, len_LAN;
  long long sum = 0;
  scanf("%d %d", &num, &neededLAN);

  for (int i = 0; i < num; i++) {
    scanf("%d", &havingLAN[i]);
    sum += havingLAN[i];  // sum은 가진 랜선의 모든 길이
  }

  maxlen = sum / neededLAN;  // 랜선의 길이가 될 수 있는 가장 큰 숫자로 초기화
  printf("%d\n", binSearch(1, maxlen, neededLAN));

  return 0;
}

int binSearch(long long min, long long max, int target) {
  if (min > max) {
    return max;
  }

  long long mid = (min + max) / 2;  // mid의 길7이는 랜선의 길이
  int num = lanNum(mid);

  if (num < target)  // mid 길이가 타겟보다 길 때
    binSearch(min, mid - 1, target);
  else {  // mid 길이가 타겟보다 짧을 때 (더 많은 수 포함)
    if (num == target && lanNum(mid + 1) != target)
      return mid;
    else if (lanNum(mid + 1) < target)
      return mid;
    else
      binSearch(mid + 1, max, target);
  }
}

// 랜선 길이대로 잘랐을 때 랜선의 개수
int lanNum(long long mid) {
  int len_LAN = 0;
  for (int i = 0; i < num; i++) {
    len_LAN += havingLAN[i] / mid;
  }
  return len_LAN;
}