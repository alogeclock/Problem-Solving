// idea: BFS review
// queue<pair<int, int>> 사용법 배우기

#include <bits/stdc++.h>
using namespace std;
#define MAX_ROW 1000

const int dr[] = {-1, 0, 1, 0};  // 상좌하우
const int dc[] = {0, -1, 0, 1};
int m[MAX_ROW][MAX_ROW];  // 0으로 초기화
int visited[MAX_ROW][MAX_ROW];

int row, col;
int goal[2];

void find_path() {
  queue<pair<int, int>> q;  // pair queue
  int nx, ny;

  q.push({goal[0], goal[1]});

  while (q.size() > 0) {
    int path_len = visited[q.front().first][q.front().second];

    for (int i = 0; i < 4; i++) {
      int nr = q.front().first + dr[i];
      int nc = q.front().second + dc[i];

      // 좌표상 못 가면 continue
      if (nr < 0 || nc < 0 || nr >= row || nr >= col)
        continue;

      // 방문 가능하면 BFS
      if (!visited[nr][nc] && m[nr][nc] == 1) {
        q.push({nr, nc});
        visited[nr][nc] = path_len + 1;
      }
    }

    q.pop();
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> row >> col;

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cin >> m[i][j];
      if (m[i][j] == 2) {
        goal[0] = i;  // row
        goal[1] = j;  // col
      }
    }
  }

  find_path();

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (!visited[i][j] && m[i][j] == 1)
        visited[i][j] = -1;
      cout << visited[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}