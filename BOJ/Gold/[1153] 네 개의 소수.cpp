// idea: counting, goldbach's conjecture

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007

int vst[1000100];

void sieve(vector<int> &prime) {
  for (int i = 2; i <= 1000000; i++) {
    if (vst[i]) continue;
    prime.push_back(i);
    for (int j = i; j <= 1000000; j += i) vst[j] = 1;
  }
}

// 1,000,000까지 소수의 개수 78,498개 → O(n^4) = TLE
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int N; cin >> N;

  if (N < 8) {
    cout << "-1";
    return 0;
  }

  vector<int> prime;
  sieve(prime); // 1,000,000까지의 소수 구하기

  // 2보다 큰 모든 짝수는 두 소수의 합으로 표현 가능하므로,
  // 짝수면 네 수 중 두 수를 (2, 2), 홀수면 (2, 3)으로 고정

  if (N % 2 == 0) {
    N -= 4;
    cout << "2 2 ";
  }
  else { 
    N -= 5; cout << "2 3 ";
  }

  for (auto i : prime) {
    for (auto j : prime) {
      if (i + j == N) {
        cout << i << ' ' << j;
        goto EXIT;
      }
    }
  }
  EXIT:
  return 0;
}