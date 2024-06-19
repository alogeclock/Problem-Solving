#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define PINF 1000000007

int arr[200005];  // 1 ~ 200000
int del_max[200005];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N, M;
  cin >> N >> M;  // 수열 길이, 삭제할 수 있는 최대 개수

  for (int i = 0; i < N; i++) cin >> arr[i];

  // 최댓값 - 최솟값 형태일 때 정답 출력
  int i_max = arr[N - 1];
  del_max[0] = i_max;
  for (int i = 1; i <= M; i++) {
    // del_max: 오른쪽에서부터 x개 지울 수 있다고 가정할 때 우측 수열의 최대값
    i_max = max(i_max, arr[N - i - 1]);
    del_max[i] = i_max;
  }

  int ans = -INF;  // 정답으로 출력 가능한 값은 -99999~99999
  for (int i = 0; i <= M; i++) {
    // 앞에서 i개를 지우므로 뒤에서는 M-i개 지울 수 있음
    int temp = del_max[M - i] - arr[i];
    ans = max(temp, ans);
  }

  cout << ans;
}