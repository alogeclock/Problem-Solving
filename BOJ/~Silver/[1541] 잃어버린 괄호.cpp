// idea: 너무 어려운 방법부터 생각하지는 말 것

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

  int flag = 0, res = 0;  // 음수가 등장했는지 확인
  string num;

  // 첫 '-' 등장 전까지는 값을 더함, 이후엔 모든 값을 뺌
  for (auto i : S) {
    if (i == '+' || i == '-') {
      if (!flag)
        res += stoi(num);
      else
        res -= stoi(num);
      if (i == '-') flag = true;
      num.clear();
      continue;
    }
    num += i;
  }

  flag ? res -= stoi(num) : res += stoi(num);  // 마지막 숫자
  cout << res;
}