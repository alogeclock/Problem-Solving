// idea: gcd + bfs

#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)2e6 + 1)

struct Point {
  int first, end, sum;
  Point(int f, int e, int s) : first(f), end(e), sum(s){};
};

int arr[MAX_NUM];

int gcd(int i, int j) {
  if (j == 0) return i;
  return gcd(j, i % j);
}

int find(int first, int end) {  // first부터 end까지의 gcd 구함
  int GCD = arr[first];
  for (int i = first + 1; i < end; i++) {
    GCD = gcd(arr[i], GCD);
  }
  return GCD;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];

  queue<Point> q;
  q.push(Point(0, N, 0));

  int maxValue = 0;
  while (q.size()) {
    int first = q.front().first, end = q.front().end;
    int sum = q.front().sum;
    q.pop();

    if (first + 1 >= end) {
      maxValue = max(maxValue, sum + arr[first]);
      continue;
    }

    int mid = (first + end) / 2;

    q.push(Point(mid, end, sum + find(first, mid)));
    q.push(Point(first, mid, sum + find(mid, end)));
  }

  cout << maxValue << '\n';

  return 0;
}