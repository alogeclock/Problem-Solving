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

  int N;
  cin >> N;
  stack<int> s;
  while (N--) {
    int input, num;
    cin >> input;

    switch (input) {
      case 1:
        cin >> num;
        s.push(num);
        break;
      case 2:
        if (s.size()) {
          cout << s.top() << '\n';
          s.pop();
        } else
          cout << -1 << '\n';
        break;
      case 3:
        cout << s.size() << '\n';
        break;
      case 4:
        cout << s.empty() << '\n';
        break;
      case 5:
        s.empty() ? cout << -1 << '\n' : cout << s.top() << '\n';
    }
  }
}