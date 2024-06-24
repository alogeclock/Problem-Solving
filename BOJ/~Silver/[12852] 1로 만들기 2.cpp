#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007

int arr[1000100][2];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int X;
  scanf(" %d", &X);
  for (int i = 0; i <= X; i++)
    arr[i][0] = INF;
  arr[X][0] = 0;

  for (int i = X; i > 0; i--) {
    if (i % 3 == 0 && arr[i / 3][0] > arr[i][0] + 1) {
      arr[i / 3][0] = arr[i][0] + 1;
      arr[i / 3][1] = i;
    }
    if (i % 2 == 0 && arr[i / 2][0] > arr[i][0] + 1) {
      arr[i / 2][0] = arr[i][0] + 1;
      arr[i / 2][1] = i;
    }
    if (arr[i - 1][0] > arr[i][0] + 1) {
      arr[i - 1][0] = arr[i][0] + 1;
      arr[i - 1][1] = i;
    }
  }

  cout << arr[1][0] << '\n';

  stack<int> s;
  int top = 1;
  s.push(top);
  while (arr[top][1] > 0) {
    s.push(arr[top][1]);
    top = arr[top][1];
  }

  while (s.size()) {
    cout << s.top() << ' ';
    s.pop();
  }

  return 0;
}