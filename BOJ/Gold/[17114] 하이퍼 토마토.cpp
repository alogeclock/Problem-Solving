// idea: 11-th dimensional BFS

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007
#define FOR(i, j) for(int (i) = 0; (i) < (j); (i)++)
#define OUT(i, j) ((i) < 0 || (i) >= (j))

const int dir[22][11] = {
  {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1}, 

  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int M, N, O, P, Q, R, S, T, U, V, W;
  cin >> M >> N >> O >> P >> Q >> R >> S >> T >> U >> V >> W;

  int ripen = 0, tomatoes = 0;
  int box[W][V][U][T][S][R][Q][P][O][N][M];
  
  queue<tuple<int, int, int, int, int, int, int, int, int, int, int, int>> queue;
  // day, m, n, o, p, q, r, s, t, u, v, w
  FOR(w, W) FOR(v, V) FOR(u, U) FOR(t, T) FOR(s, S) FOR(r, R) FOR(q, Q) FOR(p, P) FOR(o, O) FOR(n, N) FOR(m, M) {
    cin >> box[w][v][u][t][s][r][q][p][o][n][m];
    if (box[w][v][u][t][s][r][q][p][o][n][m] == 1) {
      ripen++;
      queue.push({0, m, n, o, p, q, r, s, t, u, v, w});
    }
    if (box[w][v][u][t][s][r][q][p][o][n][m] != -1) tomatoes++;
  }

  int ans = 0;
  while (queue.size()) {
    auto [cdst, cm, cn, co, cp, cq, cr, cs, ct, cu, cv, cw] = queue.front();
    ans = max(ans, cdst);
    queue.pop();

    FOR(i, 22) {
      int ndst = cdst + 1;
      int nw = cw + dir[i][0], nv = cv + dir[i][1], nu = cu + dir[i][2], nt = ct + dir[i][3], ns = cs + dir[i][4], nr = cr + dir[i][5], nq = cq + dir[i][6], np = cp + dir[i][7], no = co + dir[i][8], nn = cn + dir[i][9], nm = cm + dir[i][10];
      if (OUT(nw, W) || OUT(nv, V) || OUT(nu, U) || OUT(nt, T) || OUT(ns, S) || OUT(nr, R) || OUT(nq, Q) || OUT(np, P) || OUT(no, O) || OUT(nn, N) || OUT(nm, M)) continue;
      if (box[nw][nv][nu][nt][ns][nr][nq][np][no][nn][nm] == 0) {
        ripen++;
        box[nw][nv][nu][nt][ns][nr][nq][np][no][nn][nm] = 1;
        queue.push({ndst, nm, nn, no, np, nq, nr, ns, nt, nu, nv, nw});
      }
    }
  }
  
  ans = (ripen == tomatoes) ? ans : -1;
  cout << ans;
}