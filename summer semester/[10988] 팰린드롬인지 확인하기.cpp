// idea: O(n·logn) 방식의 풀이
// sort를 통해 정렬한 뒤 한 번 훑어서
// 이전 값에 비해 덩치가 작다면 i값 부여, 작지 않다면 이전 rank 값 부여

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

  for (int lp = 0, rp = S.size() - 1 ; lp < rp; lp++, rp--) {
    if (S[lp] != S[rp]) {
      cout << 0;
      return 0;
    }
  }
  cout << 1;
}