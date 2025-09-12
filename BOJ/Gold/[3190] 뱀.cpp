#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

const int dr[4] = { -1, 0, 1, 0 }, dc[4] = { 0, 1, 0, -1 };
ll board[101][101];

int
main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  ll N, K;
  cin >> N >> K; // N: board size, K: number of apple
  for (int i = 1; i <= K; i++) {
    int r, c;
    cin >> r >> c;
    board[r][c] = 2; // 0: blank, 1: snake, 2: apple
  }

  ll L;
  cin >> L; // L: number of direction changes
  vector<pll> dv;
  for (int i = 0; i < L; i++) {
    ll x;
    char c;
    cin >> x >> c;

    if (c == 'L')
      dv.push_back({ x, 0 });
    else
      dv.push_back({ x, 1 });
  }

  deque<pll> q;
  q.push_back({ 1, 1 }); // initial point of snake
  board[1][1] = 1;
  ll dir = 1, timestamp = 0;
  ll dv_offset = 0;

  while (1) {
    auto [cr, cc] = q.front(); // head
    auto [tr, tc] = q.back();  // tail
    timestamp++;

    ll nr = cr + dr[dir], nc = cc + dc[dir];
    if (nr > N || nc > N || nr <= 0 || nc <= 0 || board[nr][nc] == 1)
      break;

    q.pop_back();
    board[tr][tc] = 0; // remove tail

    if (board[nr][nc] == 2) {
      q.push_front({ nr, nc });
      q.push_back({ tr, tc });
      board[nr][nc] = 1;
      board[tr][tc] = 1;
    } else {
      q.push_front({ nr, nc });
      board[nr][nc] = 1;
    }

    if (dv[dv_offset].first == timestamp) {
      if (dv[dv_offset].second == 0)
        dir = (dir - 1) % 4;
      else
        dir = (dir + 1) % 4;
      if (dir < 0)
        dir += 4;
      dv_offset++;
    }
  }

  cout << timestamp;
}