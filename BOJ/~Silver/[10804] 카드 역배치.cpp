#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int N; cin >> N;
  int Y = 0, M = 0;
  for (int i = 0; i < N; i++) {
    int time; cin >> time;
    Y += 10 * (time / 30) + 10;
    M += 15 * (time / 60) + 15;
  }
  if (Y == M) cout << "Y M " << Y;
  else if (Y < M) cout << "Y " << Y;
  else cout << "M " << M;
  
}