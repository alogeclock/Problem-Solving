// 16724 (G3) - cycle searching

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll dr[4] = {-1, 0, 1, 0}, dc[4] = {0, -1, 0, 1};
ll m[1010][1010], vst[1010][1010];
ll ans;

void dfs(ll r, ll c) {
  vst[r][c] = 1;
  ll dir = m[r][c];
  ll nr = r + dr[dir], nc = c + dc[dir];
  if (vst[nr][nc] == 0) dfs(nr, nc); // continues dfs if node is not visited
  else if (vst[nr][nc] == 1) ans++; // stop searching, detects cycle
  vst[r][c] = 2; // marks every visited nodes when dfs is finished
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  ll N, M; cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      ll x; cin >> x;
      if (x == 'U') m[i][j] = 0;
      else if (x == 'L') m[i][j] = 1;
      else if (x == 'D') m[i][j] = 2;
      else if (x == 'R') m[i][j] = 3;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (vst[i][j] == 0) dfs(i, j);
    }
  }
  
  cout << ans << '\n';   
}
