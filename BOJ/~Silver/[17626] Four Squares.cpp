// idea: hashmap

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>

ll arr[50050];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  memset(arr, 0x3f, sizeof(arr));
  vector<ll> square;
  int sq = 1;
  for (int i = 1; i <= 50000; i++) {
    if (sq * sq == i) {
      arr[i] = 1;
      square.push_back(sq * sq);
      sq++;
    }
  }

  for (auto sq : square) {
    for (int i = 1; i <= 50000; i++) {
      if (i - sq <= 0) continue;
      arr[i] = min(arr[i-sq] + 1, arr[i]);
    }
  }

  ll N; cin >> N;
  cout << arr[N] << '\n';
}