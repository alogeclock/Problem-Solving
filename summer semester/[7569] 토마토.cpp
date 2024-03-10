// debug: check the input sequence(row/col/height)

#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define PINF 1000000007
#define out_of_map(r, c, h) \
  (r < 0 || r >= N || c < 0 || c >= M || h < 0 || h >= H)

const int dr[] = {0, 1, 0, -1, 0, 0};
const int dc[] = {1, 0, -1, 0, 0, 0};
const int dh[] = {0, 0, 0, 0, 1, -1};
int box[105][105][105];

struct Tomato {
  int row, col, height, day;
  Tomato(int r, int c, int h, int d) : row(r), col(c), height(h), day(d) {}
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N, M, H;
  cin >> M >> N >> H;  // row, column, height

  int tomato = 0;
  int ripe = 0;  // number of ripe tomatoes
  queue<Tomato> q;
  for (int k = 0; k < H; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        cin >> box[k][i][j];
        if (box[k][i][j] != -1) tomato++;
        if (box[k][i][j] == 1) {
          q.push(Tomato(i, j, k, 0));
          ripe++;
        }
      }
    }
  }

  int max_day = 0;
  while (q.size()) {
    // cur_row, cur_col, cur_height, cur_day
    auto [cr, cc, ch, cd] = q.front();
    q.pop();

    max_day = max(cd, max_day);  // update max_value
    if (out_of_map(cr, cc, ch)) continue;

    for (int i = 0; i < 6; i++) {
      int nr = cr + dr[i], nc = cc + dc[i], nh = ch + dh[i];
      int nd = cd + 1;
      if (out_of_map(nr, nc, nh)) continue;
      if (!box[nh][nr][nc]) {
        box[nh][nr][nc] = 1;
        q.push(Tomato(nr, nc, nh, nd));
        ripe++;
      }
    }
  }

  (ripe == tomato) ? cout << max_day : cout << -1;
}