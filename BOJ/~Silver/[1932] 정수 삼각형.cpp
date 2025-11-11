// idea: implement

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>

ll arr[130000], vst[130000], N;

ll rec(ll idx, ll lv) {
  if (lv == N) return arr[idx];
  if (vst[idx] != 0) return vst[idx];
  ll left = arr[idx] + rec(idx + lv, lv + 1);
  ll right = arr[idx] + rec(idx + lv + 1, lv + 1);
  return vst[idx] = max(left, right);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> N;
  
  ll idx = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
      idx++; cin >> arr[idx];
    }
  }

  cout << rec(1, 1);
}