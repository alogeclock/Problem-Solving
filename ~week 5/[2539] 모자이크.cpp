// idea: binary search
// F-T 문제일 경우 rp가 가리키도록 lp--
// T-F 문제일 경우 lp가 가리키도록 rp++

#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 1)

int N, M, P;
bool booleanMap[MAX_NUM];

bool Check(int mid) {
  int paperCnt = 0;
  for (int i = 1; i < M + 1;) {
    if (!booleanMap[i]) {
      i++;
      continue;
    } else {
      if (paperCnt >= P) return 0;  // 크기가 더 커져야 함(장수 부족)
      paperCnt++;
      i += mid;
    }
  }
  return 1;  // 크기가 더 작거나 적절함
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M >> P;  // 행, 열, 색종이 장 수

  int w;
  cin >> w;

  int lp = 0, rp = max(N, M);
  for (int i = 0; i < w; i++) {
    int row, col;
    cin >> row >> col;
    booleanMap[col] = 1;
    lp = max(row, lp);
  }
  // 색종이의 최소 크기: 가장 높은 곳에 위치한 wrong
  // 최대 크기: N, M 중 큰 색종이 + 1 (lp, rp)
  // 가장 작은 색종이의 크기 = F-T 문제(right + 1)

  lp--;  // rp가 경계값에 도달할 수 있도록 lp를 줄임

  while (lp + 1 < rp) {
    int mid = (lp + rp) / 2;
    if (Check(mid))
      rp = mid;
    else
      lp = mid;
  }

  cout << rp << '\n';

  return 0;
}