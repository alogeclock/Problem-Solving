// idea: binary search
// debugging: data type, off-by-one error
// 1) first + 1 < end
// 2) bool return 함수
// 3) 최솟값일 시 first가 모든 범위 cover할 수 있도록(최댓값 시 반대)

#include <bits/stdc++.h>
using namespace std;
#define MAX_ITEMS ((int)1e6 + 1)

long long N, M, X;
long long cost[MAX_ITEMS];
long long participant[MAX_ITEMS];  // 상품별 구매수

bool check(long long mid, int curItem) {
  return X - (mid * cost[curItem]) >= (N - mid) * cost[M];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M >> X;

  for (int i = 1; i <= M; i++) {
    cin >> cost[i];
  }

  for (int i = 1; i < M; i++) {
    long long first = 0, end = N + 1;
    while (first + 1 < end) {  // first와 end 사이 다른 칸 존재 여부
      long long mid = (first + end) / 2;
      if (check(mid, i))  // 이분 탐색
        first = mid;
      else
        end = mid;
    }  // 가능한 최솟값일 시 high, 최댓값일 시 low 호출
    participant[i] = first;
    X -= first * cost[i];
    N -= first;
  }

  for (int i = 1; i < M; i++) {
    cout << participant[i] << ' ';
  }
  cout << N << '\n';

  return 0;
}