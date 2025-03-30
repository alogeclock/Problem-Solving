#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  ll N; cin >> N;
  vector<pll> pg; // pg: polygon, 삼각형으로 면적을 쪼개 계산
  for (int i = 0; i < N; i++) {
    ll x, y; cin >> x >> y; pg.push_back({x, y});
  }

  double ans = 0;
  for (int i = 1; i < N - 1; i++) {
    ll cx = pg[i].first - pg[0].first, cy = pg[i].second - pg[0].second;
    ll nx = pg[i+1].first - pg[0].first, ny = pg[i+1].second - pg[0].second;
    ans += 0.5 * (cx*ny - nx*cy);
  }
  cout.precision(1);
  cout << fixed << abs(ans);
}