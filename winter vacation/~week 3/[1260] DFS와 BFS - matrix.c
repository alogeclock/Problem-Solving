#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 1001
#define MAX_EDGES 10001
#define TRUE 1

int graph[MAX_VERTICES][MAX_VERTICES];
int edges[MAX_VERTICES];
int visited[MAX_VERTICES];  // 1~100

int queue[MAX_EDGES];
int front, rear;

int compare(const void *a, const void *b) {
  int A = *(int *)a;
  int B = *(int *)b;

  if (A > B)
    return 1;
  else
    return -1;
}

void BFS(int v) {
  queue[rear++] = v;

  while (front < rear) {
    // 값 출력, 방문 표시
    v = queue[front++];
    visited[v] = TRUE;
    printf("%d ", v);

    // 해당 vertex와 연결된 방문하지 않은 vertex를 queue에 저장
    for (int i = 0; i < edges[v]; i++) {
      if (!visited[graph[v][i]]) {
        queue[rear++] = graph[v][i];
        visited[graph[v][i]] = TRUE;
      }
    }
  }
}

void DFS(int v) {
  printf("%d ", v);
  visited[v] = TRUE;
  for (int i = 0; i < edges[v]; i++) 
    if (!visited[graph[v][i]]) DFS(graph[v][i]);
}

int main() {
  int V, E, starting_vertex;
  int src, def;
  scanf("%d %d %d", &V, &E, &starting_vertex);

  for (int i = 0; i < E; i++) {
    scanf("%d %d", &src, &def);
    graph[src][edges[src]++] = def;
    graph[def][edges[def]++] = src;
  }

  // n * nlogn
  for (int i = 1; i <= V; i++) {
    qsort(graph[i], edges[i], sizeof(int), compare);
  }

  DFS(starting_vertex);
  printf("\n");

  for (int i = 1; i <= V; i++) {
    visited[i] = 0;
  }

  BFS(starting_vertex);
  printf("\n");

  return 0;
}