#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;
  vector<pair<int, int>> l(N);

  for (int i = 0; i < N; i++) {
    int s, e;
    cin >> s >> e;
    l[i].first = s;
    l[i].second = e;
  }

  sort(l.begin(), l.end(),
       [](const pair<int, int> &a, const pair<int, int> &b) {
         return (a.first == b.first) ? a.second > b.second : a.first < b.first;
       });

  priority_queue<int, vector<int>, greater<int>> room;

  for (int i = 0; i < N; i++) {
    if (!room.empty() && room.top() <= l[i].first) room.pop();
    room.push(l[i].second);
  }

  cout << room.size();

  return 0;
}