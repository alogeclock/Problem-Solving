#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define LINF 0x3f3f3f3f3f3f3f3fLL

vector<ll> g[500500];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    ll N; cin >> N;

    ll cnt = 0;
    for (int i = 1; i < N; i++) {
      ll u, v; cin >> u >> v; 
      g[u].push_back(v);
      g[v].push_back(u);
      if (g[u].size() > 2) cnt++;
      if (g[v].size() > 2) cnt++;
    }

    cout << cnt;
}