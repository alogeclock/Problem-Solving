// idea: floyd-warshall

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007

ll g[105][105];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll N; cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> g[i][j];
      if (g[i][j] == 0) g[i][j] = LINF;
    }
  }

  for (int k = 0; k < N; k++)
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        g[i][j] = min(g[i][k] + g[k][j], g[i][j]);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      (g[i][j] == LINF) ? cout << 0 << ' ' : cout << 1 << ' ';
    }
    cout <<'\n';
  }
}