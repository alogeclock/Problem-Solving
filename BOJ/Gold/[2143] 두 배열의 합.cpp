#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

ll a[1010], b[1010];
ll psa[1010], psb[1010]; // prefix_sum_a
multiset<ll> psas, psbs;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  // idea 1: 누적 합
  ll T; cin >> T;
  ll N; cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
    psa[i] = a[i] + psa[i-1];
  }
  ll M; cin >> M;
  for (int i = 1; i <= M; i++) {
    cin >> b[i];
    psb[i] = b[i] + psb[i-1];
  }
  
  // A[j]-A[i]까지의 부 배열의 합, psa[i] - psa[j-1]
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
      psas.insert(psa[i] - psa[j-1]);
    }
  }

  // B[j]-B[i]까지의 부 배열의 합, psb[i] - psb[j-1]
  for (int i = 1; i <= M; i++) {
    for (int j = 1; j <= i; j++) {
      psbs.insert(psb[i] - psb[j-1]);
    }
  }

  // psa의 모든 부 배열의 합을 순회하며 psa(i, j) + psb(k, l) = T 확인
  ll ans = 0;
  while (!psas.empty()) {
    ll a_count = psas.count(*psas.begin());
    ll b_count = psbs.count(T - *psas.begin());
    ans += a_count * b_count;
    psbs.erase(T - *psas.begin());
    psas.erase(*psas.begin());
  }
  cout << ans;
}