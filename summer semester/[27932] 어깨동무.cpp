#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define PINF 1000000007

int N, K;  // 학생 수, 지친 사람 수의 최댓값
int height[MAX_NUM];

bool check(int mid) {
  int cnt = 0;  // 지친 학생의 수
  bool tired[MAX_NUM];
  memset(tired, 0, sizeof(tired));

  for (int i = 0; i < N - 1; i++) {
    // 다음 학생과 키 차이 > mid일 경우 갱신
    if (abs(height[i] - height[i + 1]) > mid) tired[i] = 1, tired[i + 1] = 1;
    if (tired[i]) cnt++;
  }
  if (tired[N - 1]) cnt++;

  return (cnt <= K);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N >> K;

  for (int i = 0; i < N; i++) cin >> height[i];
  // 점수 차가 클수록 지친 학생 수가 줄어들기 때문에 F-T 문제. lp - 1
  int lp = -1, rp = 1000000000;
  while (lp + 1 < rp) {
    int mid = (lp + rp) / 2;
    if (check(mid))
      rp = mid;
    else
      lp = mid;
  }

  cout << rp;
}