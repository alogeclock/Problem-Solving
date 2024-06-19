#include <bits/stdc++.h>
using namespace std;
#define MAX_NUMBER 100000

int stat[MAX_NUMBER];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> stat[i];
  }

  sort(stat, stat + N);  // 오름차순 정렬

  int cnt = 0;  // 견학 가능한 학생 수
  for (int end = (N - 1), start = 0; end > start;) {
    if (stat[end] + stat[start] >= M)
      end--, start++, cnt++;
    else
      start++;
  }

  cout << cnt << '\n';

  return 0;
}