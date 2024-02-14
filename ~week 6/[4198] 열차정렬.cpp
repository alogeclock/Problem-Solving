#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 1)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long

int weight[2010];
long long lis[2010][2010];  // 32MB
long long lds[2010][2010];  // 16MB

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N;
  cin >> N;

  if (N == 0) {
    cout << 0;
    return 0;
  }

  for (int i = 0; i < N; i++) cin >> weight[i];

  // 모든 차량에 대해 그 차량을 기준값으로 두고 lis, lds를 구함
  // n·n·logn = 2000*2000*11*2 = 88,000,000회
  // 모든 차량의 증가수열의 길이, 감소수열의 길이의 합 중 최대값이 정답

  memset(lis, 0x3f, sizeof(lis));
  memset(lds, 0x3f, sizeof(lds));

  long long ans = 0;
  for (int i = 0; i < N; i++) {
    long long lis_end = 0, lds_end = 0;
    for (int j = i + 1; j < N; j++) {
      if (weight[j] > weight[i]) {  // 기준 차량보다 무겁다면 증가수열에 입력
        int idx_lis =
            lower_bound(lis[i], lis[i] + lis_end + 5, weight[j]) - lis[i];
        lis[i][idx_lis] = weight[j];
        if (idx_lis >= lis_end) lis_end++;
      } else {  // 기준 차량보다 가볍다면 감소수열에 입력
        int idx_lds =
            lower_bound(lds[i], lds[i] + lds_end + 5, -weight[j]) - lds[i];
        lds[i][idx_lds] = -weight[j];
        if (idx_lds >= lds_end) lds_end++;
      }
    }
    ans = max(ans, lis_end + lds_end);
  }

  cout << ans + 1;
}