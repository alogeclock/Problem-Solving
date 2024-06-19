// idea: implement

#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define PINF 1000000007

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  string S;
  cin >> S;

  string kroatia[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
  int ans = 0;

  int size = (int)S.size();
  for (int i = 0; i < (int)S.length(); i++) {
    char cur_char = S[i];
    queue<int> q;
    // 현재 문자 기준 가능성이 있는 크로아티아 문자열 탐색
    for (int j = 0; j < 8; j++) {
      if (kroatia[j][0] == cur_char) q.push(j);
    }

    // 가능성이 있는 문자를 탐색
    int flag;
    while (q.size()) {
      int p = q.front();
      flag = p + 1;  // flag에 주소값을 저장

      for (int j = 1; j < (int)kroatia[p].size(); j++) {  // 알파벳 비교
        if (i + j < size && S[i + j] != kroatia[p][j]) {
          flag = 0;
          break;
        }
        if (i + j >= size) flag = 0;
      }

      // 전부 맞았으면 ans++, 주소 크기 - 1만큼 이동(나머지 1은 for문에서 처리)
      if (flag) {
        i += kroatia[flag - 1].size() - 1;
        break;
      }
      q.pop();
    }

    // 가능성이 없다면 정답 설정
    if (cur_char == '=' || cur_char == '-') continue;
    ans++;
  }

  cout << ans;
}