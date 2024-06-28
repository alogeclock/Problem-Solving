// idea: two pointer

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

  ll N; cin >> N;
  ll fibo[101]; fibo[0] = 1, fibo[1] = 2;
  for (int i = 2; i <= 100; i++) {
    fibo[i] = fibo[i - 1] + fibo[i - 2];
  }

  // 최솟값 출력
  if (N % 2 == 0) cout << N / 2 << ' ';
  else cout << (N / 2) + 1 << ' ';
  
  // 최댓값 출력
  if (N % 3 == 0) cout << (N / 3) * 2;
  if (N % 3 == 1) cout << ((N - 3) / 3) * 2 + 2;
  else if (N % 3 == 2) cout << (N / 3) * 2 + 1;
}