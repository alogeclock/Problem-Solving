// idea 1: two pq (max heap + min heap)
// idea 2: ascending order pq (<int>, vector<int>, greater<int>)
// idea 3: map<int, int> (ex: item, count)

#include <bits/stdc++.h>
#define MAX_OPERATION_NUMBER 1000001
using namespace std;

priority_queue<int> maxQ;
priority_queue<int, vector<int>, greater<int>> minQ;
map<int, int> cnt;

void clean() {
  while (!minQ.empty() && !cnt[minQ.top()])
    minQ.pop();
  while (!maxQ.empty() && !cnt[maxQ.top()])
    maxQ.pop();
}

void deleteQ(int val) {
  if (val == 1 && !maxQ.empty()) {
    cnt[maxQ.top()]--;
    maxQ.pop();
  } else if (val == -1 && !minQ.empty()) {
    cnt[minQ.top()]--;
    minQ.pop();
  }
}

void insert(int v) {
  minQ.push(v);
  maxQ.push(v);
  cnt[v]++;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int T, oper, val;
  char input;
  cin >> T;

  while (T--) {
    while (!maxQ.empty()) maxQ.pop();
    while (!minQ.empty()) minQ.pop();
    cnt.clear();
    cin >> oper;
    for (int i = 0; i < oper; i++) {
      cin >> input >> val;
      if (input == 'D') {
        deleteQ(val);
        clean();
      } else
        insert(val);
    }
    clean();
    if (minQ.empty() || maxQ.empty())
      cout << "EMPTY\n";
    else
      cout << maxQ.top() << " " << minQ.top() << endl;
  }
  return 0;
}