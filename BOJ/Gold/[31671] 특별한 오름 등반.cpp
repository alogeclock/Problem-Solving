#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007

int beauty = -1;
bool vst[2010][1010];

struct Path {
  int x, y, b; // beauty
  Path(int tx, int ty, int tb) : x(tx), y(ty), b(tb) {};
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll N, M;
  cin >> N >> M;
  for (ll i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    vst[x][y] = 1;
  }

  queue<Path> q;
  q.push(Path(0, 0, 0));
  while (q.size()) {
    int cx = q.front().x;
    int cy = q.front().y;
    int cb = q.front().b;
    q.pop();

    if (cx == 2 * N) {
      if (cy == 0) beauty = max(beauty, cb);
      continue;
    }

    int nx, ny;

    // N까지는
    if (cx < N) {
    }
    for (int i = 0; i < 2; i++) {
      nx = cx + 1;
      (i == 0) ? ny = cy + 1 : ny = cy - 1;
      // 최대 N까지 이동 가능
      if (ny < 0 || ny > N || vst[nx][ny] == 1)
        continue;
      else {
        q.push(Path(nx, ny, max(ny, cb)));
        vst[nx][ny] = 1;
      }
    }
  }

  cout << beauty;
}