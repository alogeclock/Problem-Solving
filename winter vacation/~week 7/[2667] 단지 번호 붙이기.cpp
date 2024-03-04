// idea: dfs

#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define PINF 1000000007

const int dr[] = {-1, 0, 1, 0}, dc[] = {0, -1, 0, 1};

bool m[30][30];
int vst[30][30];
vector<int> apt;
int cnt, N;

void dfs(int row, int col) {
  cnt++;              // 아파트 수 확인
  vst[row][col] = 1;  // 방문 체크

  for (int i = 0; i < 4; i++) {
    int nr = row + dr[i], nc = col + dc[i];
    if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
    if (!vst[nr][nc] && m[nr][nc]) dfs(nr, nc);  // 다음이 1이고 미방문했다면
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < s.length(); j++) {
      m[i][j] = s[j] - 48;
    }
  }

  // 등장한 모든 1에 대해 dfs 실시

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      if (!vst[i][j] && m[i][j]) {
        cnt = 0;
        dfs(i, j);
        apt.push_back(cnt);
      }

  sort(apt.begin(), apt.end());  // 오름차순 정렬

  cout << apt.size() << '\n';
  for (auto aptNumber : apt) cout << aptNumber << '\n';
}
