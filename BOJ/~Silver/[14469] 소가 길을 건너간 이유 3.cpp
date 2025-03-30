#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

bool compare(pll &a, pll &b) {
  if (a.first == b.first) return a.second > b.second;
  return a.first < b.first;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  ll N; cin >> N;
  vector<pll> v;
  
  // x: 도착시각, y: 검문시간 → x <= k && max of y value
  // N <= 100, 따라서 선형 순회 가능하지만 N이 크다면?
  for (int i = 0; i < N; i++) {
    ll x, y; cin >> x >> y; v.push_back({x, y});
  }
  sort(v.begin(), v.end(), compare);

  ll cur_time = 0;
  while (!v.empty()) {
    bool found = false; //
    ll min_arrival_time = LINF, min_arrival_idx = -1;
    for (int j = 0; j < v.size(); j++) {
      if (cur_time >= v[j].first) {
        cur_time += v[j].second;
        v.erase(v.begin() + j);
        found = true;
      }
      else {
        min_arrival_time = min(min_arrival_time, v[j].first);
        min_arrival_idx = j;
      }
    }
    if (!found) {
      cur_time = min_arrival_time + v[min_arrival_idx].second;
      v.erase(v.begin() + min_arrival_idx);
    }
  }
  cout << cur_time;
}