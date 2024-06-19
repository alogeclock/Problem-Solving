#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 1001
#define MAX_EDGES 1000001
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

void DFS(int v) {
  visited[v] = TRUE;

  for (int i = 0; i < edges[v]; i++) {
    if (!visited[graph[v][i]]) DFS(graph[v][i]);
  }
}

int connected(int V) {
  /* connected components가 몇 개인지 확인 가능
  dfs로 확인되지 않은 vertex를 확인하는 함수 */
  int i, count = 0;
  int connected_components_num = 0;

  // 방문하지 않은 vertex에 대해 한번씩 DFS 실행
  // DFS를 실행한 회수 = connected components 개수
  while (!count) {
    count = 1;
    for (i = 1; i <= V; i++) {
      if (!visited[i]) {
        count = 0;
        DFS(i);
        connected_components_num++;
        break;
      }
    }
  }

  return connected_components_num;
}

int main() {
  int V, E, starting_vertex;
  int src, def;
  scanf("%d %d", &V, &E);

  for (int i = 0; i < E; i++) {
    scanf("%d %d", &src, &def);
    graph[src][edges[src]++] = def;
    graph[def][edges[def]++] = src;
  }

  // n * nlogn
  for (int i = 1; i <= V; i++) {
    qsort(graph[i], edges[i], sizeof(int), compare);
  }

  printf("%d\n", connected(V));

  return 0;
}