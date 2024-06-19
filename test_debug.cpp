#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
#define WIDTH 5
#define VECTOR ((WIDTH) * (WIDTH))
using namespace std;

int parent[VECTOR + 1];

// 해당 노드의 부모 노드를 탐색
int find(int x) {
  if (parent[x] == x) return x;
  return parent[x] = find(parent[x]);
}

// cycle table에서 부모의 숫자가 더 작은 쪽으로 노드를 병합
void unite(int u, int v) {
  u = find(u), v = find(v);
  (u < v) ? parent[v] = u : parent[v] = u;
}

struct Edge {
  int start, end, weight;
  Edge(int s, int e, int w) : start(s), end(e), weight(w){};
  bool operator<(Edge &e) { return weight < e.weight; }
};

int main() {
  // 1 ~ 1000 범위의 난수를 생성하기 위한 기초 작업
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> dis(1, 1000);

  vector<Edge> edge; // 간선을 저장할 1차원 벡터

  // 미로의 모든 벽을 간선으로 추가(r: row, c: col)
  for (int r = 1; r <= WIDTH; r++) {
    for (int c = 1; c <= WIDTH; c++) {
      int u = (r - 1) * WIDTH + c; // 현재 노드

      // 마지막 열/행이 아닐 경우 오른쪽/아래쪽 노드와 연결
      if (c < WIDTH) edge.push_back(Edge(u, u + 1, dis(gen)));
      if (r < WIDTH) edge.push_back(Edge(u, u + WIDTH, dis(gen)));
    }
  }

  // 각 vector의 부모 노드를 나타내는 parent 배열
  for (int i = 1; i <= VECTOR; i++) {
    parent[i] = i;
  }

  sort(edge.begin(), edge.end());

  char maze[2 * WIDTH + 1][2 * WIDTH + 1];

  for (int i = 0; i <= 2 * WIDTH; i++) {
    for (int j = 0; j <= 2 * WIDTH; j++) {
      if (i % 2 == 0 || j % 2 == 0)
        maze[i][j] = 'O';
      else
        maze[i][j] = ' ';
    }
  }

  for (auto e : edge) {
    int u = e.start, v = e.end;
    if (find(u) != find(v)) {
      unite(u, v);
      int x = (u - 1) / WIDTH + (v - 1) / WIDTH + 1;
      int y = (u - 1) % WIDTH + (v - 1) % WIDTH + 1;
      maze[x][y] = ' ';
    }
  }

  for (int i = 0; i <= 2 * WIDTH; i++) {
    for (int j = 0; j <= 2 * WIDTH; j++) {
      cout << maze[i][j];
    }
    cout << '\n';
  }
}
