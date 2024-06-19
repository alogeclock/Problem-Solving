// idea: priority queue(max heap)

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int visit;
  cin >> visit;

  priority_queue<int> pq;
  int input, val;
  for (int i = 0; i < visit; i++) {
    cin >> input;
    if (input == 0) {
      if (pq.empty()) {
        cout << "-1\n";
        continue;
      }
      cout << pq.top() << "\n";
      pq.pop();
    } else {
      for (int j = 0; j < input; j++) {
        cin >> val;
        pq.push(val);
      }
    }
  }

  return 0;
}