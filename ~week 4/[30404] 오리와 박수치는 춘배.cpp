#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int gwak, wait;
  cin >> gwak >> wait;

  priority_queue<int, vector<int>, greater<int>> pq;

  for (int i = 0; i < gwak; i++) {
    int gwak_time;
    cin >> gwak_time;
    pq.push(gwak_time + wait);
  }

  int clap = 0;
  for (int time = 1; time <= 2000000; time++) {
    if (time >= pq.top()) {
      while (!pq.empty() && (time >= pq.top() - wait)) pq.pop();
      clap++;
    }
    if (pq.empty()) break;
  }

  cout << clap;

  return 0;
}