// idea: set<string> s

#include <bits/stdc++.h>
#define MAX_NUMBER 10001
using namespace std;

string string_set[MAX_NUMBER];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, M;
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> string_set[i];
  }

  sort(string_set, string_set + N);

  int count = 0;
  for (int i = 0; i < M; i++) {
    string find;
    cin >> find;

    int first = 0, end = N - 1, mid;
    while (first <= end) {
      mid = (first + end) / 2;
      if (string_set[mid] == find) {
        count++;
        break;
      } else if (string_set[mid] < find) {
        first = mid + 1;
      } else {
        end = mid - 1;
      }
    }
  }

  cout << count;

  return 0;
}