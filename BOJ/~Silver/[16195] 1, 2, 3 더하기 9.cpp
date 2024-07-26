#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000009LL

ll arr[1010][1010]; // arr[N][K], 숫자 N을 K개의 수로 나타내는 방법

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  arr[1][1] = 1;
  arr[2][1] = 1, arr[2][2] = 1;
  arr[3][1] = 1, arr[3][2] = 2, arr[3][3] = 1;

  for (int i = 4; i <= 1000; i++) {
    for (int j = 1; j <= i; j++) {
      arr[i][j] = (arr[i - 1][j - 1] + arr[i - 2][j - 1] + arr[i - 3][j - 1]) % PINF;
    }
  } 

  ll T; cin >> T;
  while (T--) {
    ll N, M; cin >> N >> M; 
    ll sum = 0;
    for (int i = 0; i <= M; i++) sum = (sum + arr[N][i]) % PINF;
    cout << sum << '\n';
  }
}

// ■ check list ■
// 1. overflow, data type, memset. ==, >=, >
// 2. first visit, % MOD