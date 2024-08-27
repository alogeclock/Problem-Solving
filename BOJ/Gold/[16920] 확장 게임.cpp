#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007LL

const ll dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
ll g[1010][1010], vst[1010][1010], castle[1010][1010];
ll player_score[10], player_move[10];
vector<pll> player[10];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  memset(vst, 0x3f, sizeof(vst));
  memset(castle, 0x3f, sizeof(castle));
  ll R, C, P;
  cin >> R >> C >> P;
  for (int i = 0; i < P; i++)
    cin >> player_move[i];

  for (int r = 0; r < R; r++) {
    string s;
    cin >> s;
    for (int c = 0; c < C; c++) {
      if (s[c] == '#') g[r][c] = 1;
      if (s[c] == '.') g[r][c] = 0;
      if (s[c] >= '1' && s[c] <= '9') {
        player[s[c] - '1'].push_back({r, c});
        g[r][c] = 1, vst[r][c] = 0, castle[r][c] = s[c] - '1';
      }
    }
  }

  for (int p = 0; p < P; p++) {
    queue<tuple<ll, ll, ll>> q;
    for (auto [r, c] : player[p])
      q.push({r, c, 0});

    while (q.size()) {
      auto [cr, cc, cdst] = q.front();
      q.pop();

      for (int i = 0; i < 4; i++) {
        ll nr = cr + dr[i], nc = cc + dc[i], ndst = cdst + 1;

        if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
        if (g[nr][nc]) continue;
        if (((ndst - 1) / player_move[p] + 1) >= vst[nr][nc]) continue;

        vst[nr][nc] = (ndst - 1) / player_move[p] + 1;
        castle[nr][nc] = p;

        q.push({nr, nc, ndst});
      }
    }
  }

  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      if (castle[r][c] == LINF) continue;
      player_score[castle[r][c]]++;
    }
  }

  for (int p = 0; p < P; p++)
    cout << player_score[p] << ' ';
}

// ■ check list ■
// 1. overflow, data type, memset. ==, >=, >
// 2. first visit, % MOD