#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  ll N, L; cin >> N >> L; // number of leakage, tape length
  vector<int> leakage;
  for (int i = 0; i < N; i++) {
    ll temp; cin >> temp; 
    leakage.push_back(temp);
  }

  sort(leakage.begin(), leakage.end());

  int current = -1, tape_count = 0;
  for (auto i : leakage) {
    if (current < i) {
      current = i + L - 1;
      tape_count++;
    }
    else continue;
  }

  cout << tape_count;

  return 0;
}