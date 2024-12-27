#include <bits/stdc++.h>
using namespace std;

int beauty = -1;
bool vst[2001][1001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int N, M; cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int x, y; cin >> x >> y;
    vst[x][y] = 1;
  }

  queue<tuple<int, int, int>> q;
  q.push({0, 0, 0});
  while (q.size()) {
    auto [cx, cy, cb] = q.front();
    q.pop();

    if (cx == 2 * N) {
      if (cy == 0) beauty = max(beauty, cb);
      continue;
    }

    int nx, ny;
    for (int i = 0; i < 2; i++) {
      nx = cx + 1;
      (i == 0) ? ny = cy + 1 : ny = cy - 1;
      // 최대 N까지 이동 가능
      if (ny < 0 || ny > N || vst[nx][ny] == 1) continue;
      q.push({nx, ny, max(ny, cb)});
      vst[nx][ny] = 1;
    } 
  }

  cout << beauty;
}