#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1002
#define MAX_EDGES 100002

#define HEAP_FULL(n) (n == MAX_VERTICES - 1)
#define HEAP_EMPTY(n) (!n)
#define TRUE 1
#define FALSE 0

typedef struct element {
  int src, des, weight;
} element;

element heap[MAX_EDGES]; // edge들의 정보
int parent[MAX_VERTICES];
int edge_num = 1; // heap이 비어 있을 때 delete_min_heap이 호출되지 않도록 1로 초기화

void insert_min_heap(element item, int *n);
element delete_min_heap(int *n);
void dset_init(int n);
int simpleFind(int i);
void weightedUnion(int i, int j);

int main() {
  int computer, line, i;
  int src, des, weight;
  int src_set, des_set;
  int min_cost = 0;
  int edge_count = 0;
  element current_heap;

  scanf("%d", &computer);
  scanf("%d", &line);

  for (i = 0; i < line; i++) {
    scanf("%d %d %d", &src, &des, &weight);
    current_heap.src = src;
    current_heap.des = des;
    current_heap.weight = weight;
    insert_min_heap(current_heap, &edge_num);
  }

  dset_init(computer);
  for (; edge_count < computer - 1;) {
    current_heap = delete_min_heap(&edge_num);
    src_set = simpleFind(current_heap.src);
    des_set = simpleFind(current_heap.des);
    if (src_set != des_set) {
      min_cost += current_heap.weight;
      weightedUnion(src_set, des_set);
      edge_count++;
    }
  }
  printf("%d\n", min_cost);

  return 0;
}

void insert_min_heap(element edge, int *edge_num) {
  int i;
  i = ++(*edge_num);
  while ((i != 1) && (edge.weight < heap[i / 2].weight)) {
    heap[i] = heap[i / 2];
    i /= 2;
  }
  heap[i] = edge;
}

element delete_min_heap(int *n) {
  int parent, child;
  element item, temp;

  item = heap[1];
  temp = heap[(*n)--];
  parent = 1;
  child = 2;
  while (child <= *n) {
    if ((child < *n) && (heap[child].weight > heap[child + 1].weight)) child++;
    if (temp.weight <= heap[child].weight) break;
    heap[parent] = heap[child];
    parent = child;
    child *= 2;
  }
  heap[parent] = temp;
  return item;
}

void dset_init(int n) { // disjoint set initialize
  for (int i = 0; i < n; i++)
    parent[i] = -1;
}

int simpleFind(int i) {
  for (; parent[i] >= 0; i = parent[i])
    ;
  return i;
}

void weightedUnion(int i, int j) { // 가장 부모 노드 외엔 음수 노드 없음
  // count field 추가
  int temp = parent[i] + parent[j];
  if (parent[i] > parent[j]) {
    parent[i] = j; // j를 부모 노드로
    parent[j] = temp;
  } else {
    parent[j] = i; // i를 부모 노드로
    parent[i] = temp;
  }
}