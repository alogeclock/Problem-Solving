#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int key;
  struct node *link;
} node;
typedef node *np;

np head = NULL;
np tail = NULL;

void createNode(int key) {
  np newNode = (np)malloc(sizeof(node));
  newNode->key = key;

  if (head == NULL) {
    head = newNode;
    tail = newNode;
  } else {
    tail->link = newNode;
    tail = newNode;
  }

  newNode->link = head;
}

void delNode(np *node, int K) {
  np prev = NULL;
  np cur = *node;  // tail

  printf("<");
  while (cur->link != cur) {
    for (int i = 0; i < K - 1; i++) {
      cur = cur->link;
    }
    printf("%d, ", cur->link->key);
    prev = cur->link;
    cur->link = cur->link->link;
    free(prev);
  }

  printf("%d>\n", cur->key);
  free(cur);
}

int main() {
  int N, K;
  scanf("%d %d", &N, &K);

  for (int i = 1; i <= N; i++) {
    createNode(i);
  }

  delNode(&tail, K);

  return 0;
}