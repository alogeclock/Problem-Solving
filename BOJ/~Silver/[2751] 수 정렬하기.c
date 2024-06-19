// 힙 정렬

#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 1000001

int heap[MAX_ELEMENT];
int heap_size = 0;

void insert_min_heap(int key) {
  int i;
  i = ++heap_size;

  while ((i != 1) && (key < heap[i / 2])) {
    heap[i] = heap[i / 2];
    i /= 2;
  }
  heap[i] = key;
}

int delete_min_heap() {
  int parent, child;
  int key, temp;

  key = heap[1];
  temp = heap[heap_size--];  // 마지막 노드

  parent = 1;
  child = 2;

  // 자식 노드가 존재한다면
  while (child <= heap_size) {
    // 자식이 둘 모두 존재하고, 오른쪽 자식 노드가 더 작다면 오른쪽 노드로 이동
    if (child < heap_size && (heap[child] > heap[child + 1])) {
      child++;
    }
    // temp가 더 작은 자식 노드보다 작다면 while문 중지 (parent에 삽입)
    if (temp <= heap[child]) {
      break;
    }

    // 더 큰 자식 노드보다 마지막 노드가 작으면, 부모 노드와 더 큰 자식 노드 교환
    heap[parent] = heap[child];
    parent = child;
    child *= 2;
  }

  // 마지막 노드를 새 위치에 삽입
  heap[parent] = temp;
  // 최댓값 반환
  return key;
}

int main() {
  int N, key;

  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    scanf("%d", &key);
    insert_min_heap(key);
  }

  for (int i = 0; i < N; i++) {
    printf("%d\n", delete_min_heap());
  }

  return 0;
}