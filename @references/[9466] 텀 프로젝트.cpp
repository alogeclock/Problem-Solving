// idea: vst 3 division(-1, 0, 1), **divide each trial by 'i'
// 이번 시행에서 방문했는지, 아닌지를 i를 입력해 씀으로써 구분 가능

#include <iostream>
using namespace std;
#define MAX_NUMBER 100001

int arr[MAX_NUMBER];
int vst[MAX_NUMBER];
int team_count = 0;

void find_team(int i) {
  int cur = i;
  while (1) {
    vst[cur] = i;
    cur = arr[cur];
    if (vst[cur] == i) {
      while (vst[cur] != -1) {
        team_count++;
        vst[cur] = -1;
        cur = arr[cur];
      }
      return;
    } else if (vst[cur] != 0)
      return;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;

  while (T--) {
    team_count = 0;
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) cin >> arr[i];
    fill(vst + 1, vst + N + 1, 0);

    for (int i = 1; i <= N; i++)
      if (vst[i] == 0) find_team(i);
    cout << N - team_count << '\n';
  }

  return 0;
}