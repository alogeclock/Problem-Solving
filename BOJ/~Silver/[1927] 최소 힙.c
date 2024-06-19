#include <stdio.h>
#define MAX_ARRAY_SIZE 100001

int arr[MAX_ARRAY_SIZE] = {0};
int ans[MAX_ARRAY_SIZE];
int order = 0;
int size = 0;

void insert_min_heap(int key) {
  int i = ++size;

  while ((i != 1) && (key < arr[i / 2])) {
    arr[i] = arr[i / 2];
    i /= 2;
  }
  arr[i] = key;
}

void delete_min_heap() {
  int parent = 1, child = 2;
  int temp = arr[size];

  // 0이라면 0 입력, 존재한다면 자연수 입력
  if (size > 0) {
    ans[order++] = arr[1];
  } else {
    ans[order++] = 0;
    return;
  }

  while (child <= size) {
    if ((child < size) && (arr[child] > arr[child + 1])) child++;
    if (temp < arr[child]) break;
    arr[parent] = arr[child];
    parent = child;
    child *= 2;
  }
  arr[parent] = temp;

  size--;
}

int main() {
  int N, input;
  scanf("%d", &N);

  while (N--) {
    scanf("%d", &input);

    if (input == 0)
      delete_min_heap();
    else
      insert_min_heap(input);
  }

  for (int i = 0; i < order; i++) {
    printf("%d\n", ans[i]);
  }

  return 0;
}