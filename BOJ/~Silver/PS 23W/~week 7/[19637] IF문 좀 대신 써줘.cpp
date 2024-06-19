#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define PINF 1000000007

string name[100005];
int power[100005];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N, M;
  cin >> N >> M;
  memset(power, 0x3f, sizeof(power));

  // 칭호명은 전투력 순으로 정렬됨
  for (int i = 0; i < N; i++) cin >> name[i] >> power[i];

  // 이분 탐색
  int user_power;
  for (int i = 0; i < M; i++) {
    cin >> user_power;
    int idx = lower_bound(power, power + N + 5, user_power) - power;
    cout << name[idx] << '\n';
  }
}
