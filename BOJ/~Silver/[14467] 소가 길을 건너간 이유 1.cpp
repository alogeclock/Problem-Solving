#include <iostream>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

ll vst[11], pos[11], ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  ll N; cin >> N;
  
  for (int i = 0; i < N; i++) {
    ll idx, move; cin >> idx >> move;
    if (!vst[idx]) vst[idx] = 1;
    else if (pos[idx] != move) ans++;
    pos[idx] = move;
  }
  cout << ans;
}