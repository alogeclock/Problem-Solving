#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

ll F, S, G, U, D;
ll vst[1001000], ds[2];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> F >> S >> G >> U >> D;
  ds[0] = U, ds[1] = -D;
  memset(vst, 0x3f, sizeof(vst));
  queue<ll> q; q.push(S); vst[S] = 1;

  while (q.size()) {
    ll cs = q.front(), cdst = vst[cs];
    q.pop();
    
    for (int i = 0; i < 2; i++) {
      ll ns = cs + ds[i], ndst = cdst + 1;
      if (ns <= 0 || ns > F || vst[ns] <= ndst) continue;
      
      vst[ns] = ndst;
      q.push(ns);
    }
  }

  (vst[G] == LINF) ? cout << "use the stairs" : cout << vst[G] - 1;
}