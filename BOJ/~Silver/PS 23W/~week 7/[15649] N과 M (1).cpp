// backtracking

#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF ((int)1e9 + 7)
#define ll long long

int N, M;
int state[10];
bool vst[10];

void backtracking(int k) {
  if (k == M) {  // 종료 조건을 만족했을 때 회귀
    for (int i = 0; i < M; i++) cout << state[i] << ' ';
    cout << '\n';
    return;
  }

  for (int i = 1; i <= N; i++) {
    if (!vst[i]) {          // 수 i에 방문하지 않았다면
      state[k] = i;         // 현재 상태 배열에 수 입력
      vst[i] = true;        // 방문 상태 확인
      backtracking(k + 1);  // 다음 상태로 이동한 뒤에
      vst[i] = false;       // 돌아오면서 원래 상태로 복구
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> N >> M;
  backtracking(0);
}