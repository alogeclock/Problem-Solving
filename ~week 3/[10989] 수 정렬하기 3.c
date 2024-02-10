#include <stdio.h>
#define MAX_NUM_SIZE 10001

int arr[MAX_NUM_SIZE];
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

  printf("%d\n", arr[1]);

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

  for (int i = 0; i < N; i++) {
    scanf("%d", &input);
    arr[input]++;
  }

  for (int i = 1; i < MAX_NUM_SIZE; i++) {
    for (int j = 0; j < arr[i]; j++) {
      printf("%d\n", i);
    }
  }
}