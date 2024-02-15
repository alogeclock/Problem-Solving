// idea: dp
// 이미 고른 강의와 겹치지 않는 강의 중 가장 종료 시간이 빠른 강의
// 시작하자마자 끝나는 강의를 고려하는 꼼꼼함이 중요

#include <stdio.h>
#include <stdlib.h>
#define MAX_LECTURE_NUMBER 100001

typedef struct lecture {
  int start;
  int end;
} Lecture;
Lecture lecture[MAX_LECTURE_NUMBER];

int current_end = 0;
int lecture_num = 0;

// 종료시간 기준 오름차순 정렬
int compare(const void *a, const void *b) {
  Lecture A = *(Lecture *)a;
  Lecture B = *(Lecture *)b;

  if (A.end > B.end) return 1;
  if (A.end < B.end) return -1;

  // A.end == B.end
  if (A.start < B.start)
    return -1;
  else
    return 1;
}

int main() {
  int N;
  scanf("%d", &N);

  // 강의 입력받은 후 정렬
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &lecture[i].start, &lecture[i].end);
  }
  qsort(lecture, N, sizeof(Lecture), compare);

  // 가장 일찍 종료하며 + current_end(지금까지 강의의 종료시간)보다 크거나 같은 강의
  for (int i = 0; i < N; i++) {
    if (current_end <= lecture[i].start) {
      current_end = lecture[i].end;
      lecture_num++;
    }
  }

  printf("%d\n", lecture_num);

  return 0;
}