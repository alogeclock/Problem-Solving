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

  char s[50];
  cin >> s;

  char wolf[4] = {'w', 'o', 'l', 'f'};
  int last = -1, count = 0, max_count = 0;
  bool wrong = false;
  int finish = -1;

  for (auto i : s) {
    if (i == 0) {
      if (finish != 1)
        wrong = true;
      break;
    }

    int cur;
    // 현재 문자열 포인팅
    for (int j = 0; j < 4; j++) {
      if (i == wolf[j])
        cur = j;
    }

    if (last == -1) {
      finish = 0;
      if (cur != 0)
        wrong = true;
      count++, max_count++;
      last = cur;
      continue;
    }

    if (cur == last) {
      count++;
      if (cur == 0)
        max_count++;
      else if (count > max_count) // 'w'가 아닌데 count가 max_count보다 크다면 out
        wrong = true;
      // 'f' 숫자가 맞다면 넘김, 만약 틀려 있었다면 다음에 f로 시작하면서 오류 검출됨
      if (cur == 3 && count == max_count) {
        count = 0, max_count = 0;
        last = -1; // 처음으로 초기화
        finish = 1;
        continue;
      }
    }

    if (cur != last) {
      // 제대로 된 문자의 순서가 아니거나, 문자열 길이가 다르면
      if (cur != last + 1 || count < max_count)
        wrong = true;
      count = 1; // count 초기화
      if (cur == 3 && count == max_count) {
        count = 0, max_count = 0;
        last = -1, finish = 1;
        continue;
      }
    }

    // 이전 문자열 포인팅
    last = cur;
  }
  if (count != max_count)
    wrong = true;

  (wrong) ? cout << 0 : cout << 1;
}