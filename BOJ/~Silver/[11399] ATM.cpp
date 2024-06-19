#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  long long sum = 0;
  int elapsed_time = 0;
  int user;

  cin >> user;
  vector<int> time(user);

  for (int i = 0; i < user; i++) cin >> time[i];

  sort(time.begin(), time.end());  // 오름차순 정렬이 기본

  for (int i = 0; i < user; i++) {
    elapsed_time += time[i];
    sum += elapsed_time;
  }

  cout << sum << "\n";

  return 0;
}