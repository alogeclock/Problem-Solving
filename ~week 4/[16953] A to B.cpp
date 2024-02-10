// idea: basic BFS
// debugging: long long(*10 + 1, int를 넘어설 가능성)

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  long long A, B;
  cin >> A >> B;

  queue<pair<int, int>> q;
  q.push({A, 0});

  int least = 1000;
  while (!q.empty()) {
    long long val = q.front().first;
    int calNum = q.front().second;
    q.pop();

    if (val == B && calNum < least) least = calNum;
    if (val * 2 <= B) q.push({val * 2, calNum + 1});
    if ((val * 10) + 1 <= B) q.push({(val * 10 + 1), calNum + 1});
  }

  if (least == 1000)
    cout << "-1\n";
  else
    cout << least + 1 << "\n";

  return 0;
}