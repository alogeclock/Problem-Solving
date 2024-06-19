// idea: min heap에 삽입, 삭제

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// min heap
priority_queue<ll, vector<ll>, greater<ll>> slime;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, Q, x, y, input, zero = 0;
  cin >> N >> Q;
  for (int i = 0; i < N; i++) {
    cin >> input;
    if (!input)
      zero++;
    else
      slime.push(input);
  }

  stack<ll> newSize;
  for (int i = 0; i < Q; i++) {
    cin >> x >> y;
    if (y == 1) continue;
    while (!slime.empty() && slime.top() <= x) {
      ll newValue = slime.top() * y;
      if (newValue == 0)
        zero++;
      else
        newSize.push(newValue);
      slime.pop();
    }
    while (!newSize.empty()) {
      slime.push(newSize.top());
      newSize.pop();
    }
  }

  // 출력
  for (int i = 0; i < zero; i++) cout << "0 ";

  while (!slime.empty()) {
    cout << slime.top() << ' ';
    slime.pop();
  }
  cout << '\n';

  return 0;
}