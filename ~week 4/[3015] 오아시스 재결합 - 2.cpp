// idea: stack, 반복문의 엄밀한 조정

#include <bits/stdc++.h>
using namespace std;

int top = 0;
long long counter = 0;
stack<pair<int, int>> s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;
  int *arr = new int[N];
  for (int i = 0; i < N; i++) {
    int val;
    cin >> val;

    int cnt = 1;
    while (!s.empty()) {
      if (s.top().first < val) {
        counter += s.top().second;
        cnt = 1;
        s.pop();
      } else if (s.top().first == val) {
        counter += s.top().second;
        cnt = s.top().second + 1;
        s.pop();
      } else {
        counter++;
        break;
      }
    }
    s.push({val, cnt});
  }

  cout << counter << endl;
  delete[] arr;
}