#include <bits/stdc++.h>
#define MAX_LECTURE_NUMBER 100001
using namespace std;

int current_end = 0;
int lecture_num = 0;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;
  vector<pair<int, int>> lecture(N);

  for (int i = 0; i < N; i++) {
    int s, e;
    cin >> s >> e;
    lecture[i].first = s;
    lecture[i].second = e;
  }

  sort(lecture.begin(), lecture.end(),
       [](const pair<int, int> &a, const pair<int, int> &b) {
         return (a.second == b.second) ? a.first < b.first
                                       : a.second < b.second;
       });

  for (int i = 0; i < N; i++) {
    if (current_end <= lecture[i].first) {
      current_end = lecture[i].second;
      lecture_num++;
    }
  }

  cout << lecture_num;

  return 0;
}