#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

ll vst[100100];

void sieve() {
  for (int i = 2; i <= 100000; i++) {
    if (!vst[i]) for (int j = i; j <= 100000; j += i) vst[j] = i;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  sieve();
  ll N, K; cin >> N >> K;
  
  ll ans = 0;
  for (int i = 1; i <= N; i++) if (vst[i] <= K) ans++;

  cout << ans;
}

// ■ check list ■
// 1. overflow, data type, memset. ==, >=, >
// 2. first visit, % MOD