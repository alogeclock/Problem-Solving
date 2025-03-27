#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007

ll arr[1010], correct_time[1010]; // 각 시작점별로 수정 시간을 저장

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll N, K; cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> arr[i];

  for (int i = 1; i <= 1000; i++) { // 시작점 i
    for (int j = 0; j < N; j++) { // 배열을 전부 K를 더해가며 확인
      if (arr[j] != i + K * j) correct_time[i]++;
    }
  }

  ll ans = LINF;
  for (int i = 1; i <= 1000; i++) ans = min(ans, correct_time[i]);
  cout << ans;
}