#include <stdio.h>
#define MAX_VERTICES 1001
#define MAX_EDGES 10001

typedef struct node {
  int vertex;
  struct node *link;
} node;
typedef node *nodePointer;

nodePointer rear[MAX_VERTICES];   // 1 ~ 1000
nodePointer graph[MAX_VERTICES];  // head
int visited[MAX_EDGES];

void insert_node() {
  int src, def;
  scanf("%d %d", &src, &def);
  nodePointer newNode = (nodePointer)malloc(sizeof(node));
  newNode->vertex = def;
  newNode->link = NULL;

  if (graph[src] != NULL) {
    rear[src]->link = newNode;
  } else {
    graph[src] = newNode;
  }
  rear[src] = newNode;

  nodePointer newNode = (nodePointer)malloc(sizeof(node));
  newNode->vertex = src;
  newNode->link = NULL;

  if (graph[def] != NULL) {
    rear[def]->link = newNode;
  } else {
    graph[def] = newNode;
  }
  rear[def] = newNode;
}

void DFS(int v) {
  nodePointer np;
  printf("%d ", v);
  visited[v] = 1;

  for (np = graph[v]; np; np->link) {
    if (!visited[np->vertex]) DFS(np->vertex);
  }
}

void BFS(int v) {
  printf("%d ", v);
  visited[v] = 1;
}

int main() {
  int V, E, starting_vertex;
  scanf("%d %d %d", &V, &E, &starting_vertex);

  for (int i = 0; i < E; i++) {
    insert_node();
  }

  DFS(starting_vertex);
  printf("\n");

  for (int i = 0; i < E; i++) {
    visited[i] = 0;
  }

  BFS(starting_vertex);
}