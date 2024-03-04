// idea: linked list with BFS
// 2차원 배열이 더 만들기 쉽겠지만, 연습을 위해 linked list 활용

// 시간 필요 이상 오래 소모함, 아래는 원인;
// 1. while문으로 연결 리스트를 읽을 때의 기본적인 문법에서 실수
// 2. 비방향성 그래프를 링크드 리스트로 만드는 기본적인 방법 헷갈림
// point: 그래프를 연결 리스트로 생성하는 좀 더 쉬운 방법은 없을까? (C++ 공부할
// 때)

#include <stdio.h>
#include <stdlib.h>
#define MAX_COMPUTER_NUMBER 101
#define MAX_EDGE_NUMBER 10001

typedef struct node {
  int vertex;  // 목적지 vertex
  struct node* link;
} node;
typedef node* node_pointer;

node_pointer head[MAX_COMPUTER_NUMBER];
node_pointer computer[MAX_COMPUTER_NUMBER];
int queue[MAX_EDGE_NUMBER];
int visited[MAX_COMPUTER_NUMBER];
int virus;

// 컴퓨터 쌍 연결관계 입력
void insert_node(int start, int end) {
  node_pointer new = (node_pointer)malloc(sizeof(node));
  new->vertex = end;
  new->link = NULL;

  if (!head[start])
    head[start] = new;
  else
    computer[start]->link = new;
  computer[start] = new;

  node_pointer rev = (node_pointer)malloc(sizeof(node));
  rev->vertex = start;
  rev->link = NULL;

  if (!head[end])
    head[end] = rev;
  else
    computer[end]->link = rev;
  computer[end] = rev;
}

void bfs() {
  int front = -1, rear = 0;
  queue[0] = 1;
  visited[1] = 1;

  // queue의 front에 있는 vertex에서부터 bfs() 반복

  while (front < rear) {
    front++;
    int src = queue[front];

    // queue[front]번째 vertex와 연결된 모든 노드 큐에 저장
    while (head[src]) {
      // 단, 방문하지 않은 노드일 경우에만 저장
      int def = head[src]->vertex;
      node_pointer del = head[src];

      if (visited[def] == 0) {
        rear++;
        virus++;            // 바이러스에 걸린 컴퓨터 수를 세고
        queue[rear] = def;  // queue에 목적 vertex를 넣고
        visited[def] = 1;   // 노드에 방문 표시
      }

      head[src] = head[src]->link;
      free(del);
    }
  }
}

int main() {
  int vertex, edge;
  scanf("%d %d", &vertex, &edge);

  // linked list를 통한 그래프 생성
  for (int i = 0; i < edge; i++) {
    int start, end;
    scanf("%d %d", &start, &end);
    insert_node(start, end);
  }

  bfs();

  printf("%d\n", virus);

  return 0;
}