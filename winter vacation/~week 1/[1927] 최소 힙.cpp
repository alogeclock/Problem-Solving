// idea: min heap with C++ (by priority queue)

#include <bits/stdc++.h>
using namespace std;
#define MAX_ARRAY_SIZE 100001

priority_queue<int, vector<int>, greater<int>> arr;  // important
int ans[MAX_ARRAY_SIZE];
int order, heap_size;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, input;
  cin >> N;

  while (N--) {
    cin >> input;

    if (input == 0) {
      if (heap_size > 0) {
        ans[order++] = arr.top();
        arr.pop();
        heap_size--;
      } else
        ans[order++] = 0;
    } else {
      arr.push(input);
      heap_size++;
    }
  }

  for (int i = 0; i < order; i++) {
    cout << ans[i] << "\n";
  }

  return 0;
}