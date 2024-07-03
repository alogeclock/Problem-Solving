#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007

bool compare(pll &a, pll &b) {
  return a.first < b.first;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll T, V;       // problem solving time, number of incorrect verdicts
  vector<pll> v; // solving time and incorrect verdicts
  while (cin >> T >> V) v.push_back({T, V});

  sort(v.begin(), v.end(), compare);

  int solving_time = 0, elapsed_time = 0;
  for (auto cur : v) {
    int time = cur.first, error = cur.second;
    elapsed_time += time;
    solving_time += elapsed_time + 20 * error;
  }

  cout << solving_time;

  return 0;
}