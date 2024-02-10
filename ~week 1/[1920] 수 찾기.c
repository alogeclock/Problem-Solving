// 이진 탐색 트리 구현

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 100001

typedef struct tree {
  int key;
  struct tree *left_child, *right_child;
} tree;
typedef tree* tree_pointer;
bool answer[MAX_ELEMENTS];

tree_pointer insertNode(tree_pointer node, int val) {
  tree_pointer ptr;
  if (!node) {
    ptr = (tree_pointer)malloc(sizeof(tree));
    ptr->key = val;
    ptr->left_child = ptr->right_child = NULL;
    return ptr;
  }

  if (val < node->key)
    node->left_child = insertNode(node->left_child, val);
  else
    node->right_child = insertNode(node->right_child, val);
  return node;
}

bool search(tree_pointer node, int val) {
  while (node) {
    if (val == node->key)
      return 1;
    if (val < node->key)
      node = node->left_child;
    else
      node = node->right_child;
  }
  return 0;
}

int main() {
  int N, M, val, i;
  tree_pointer root = NULL;

  scanf("%d", &N);

  for (i = 0; i < N; i++) {
    scanf("%d", &val);
    root = insertNode(root, val);
  }

  scanf("%d", &M);

  for (i = 0; i < M; i++) {
    scanf("%d", &val);
    answer[i] = search(root, val);
  }

  for (i = 0; i < M; i++) {
    printf("%d\n", answer[i]);
  }

  return 0;
}