// idea: implement, stringstream(string), token >> number

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

  // R = 뒤집기, D = 버리기(첫째 수)
  int T;
  cin >> T;

  while (T--) {
    string P;  // RDD
    int N;
    cin >> P >> N;

    string num;  // [1,2,3,4]
    cin >> num;

    stringstream token(num);
    vector<int> arr;
    char bracket, comma;
    int number;

    // 문자열 파싱
    token >> bracket;
    while (token >> number) {
      arr.push_back(number);
      token >> comma;
      if (comma == ']') break;
    }

    bool error_flag = false;
    int start = 0, end = arr.size() - 1, size = arr.size();
    int temp;

    for (auto i : P) {
      if (i == 'R') {
        temp = start;
        start = end;
        end = temp;
      } else {
        if (size) {
          if (start >= end)
            start--;
          else
            start++;
          size--;
        } else {
          error_flag = true;
          cout << "error\n";
          break;
        }
      }
    }

    if (error_flag) continue;
    if (!size) {
      cout << "[]\n";
      continue;
    }

    cout << '[';
    if (start <= end) {
      for (int i = start; i <= end; i++) {
        cout << arr[i];
        if (i < end) cout << ',';
      }
    } else {
      for (int i = start; i >= end; i--) {
        cout << arr[i];
        if (i > end) cout << ',';
      }
    }
    cout << "]\n";
  }

  return 0;
}