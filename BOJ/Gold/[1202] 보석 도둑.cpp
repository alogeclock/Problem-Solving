#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

vector<pll> gems;
multiset<ll> bags;

bool compare(pll a, pll b) {
  return a.second > b.second;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  ll N, K; cin >> N >> K;
  for (int i = 0; i < N; i++) {
    ll w, p; cin >> w >> p; gems.push_back({w, p});
  }
  for (int i = 0; i < K; i++) {
    ll w; cin >> w; bags.insert(w);    
  }

  sort(gems.begin(), gems.end(), compare);

  // 비싼 순서대로 넣을 수 있는 가장 작은 가방에 넣기
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    ll weight = gems[i].first;
    set<ll>::iterator it = bags.lower_bound(weight);
    if (it != bags.end()) {
      ans += gems[i].second;
      bags.erase(it);
    }
  }

  cout << ans;
}