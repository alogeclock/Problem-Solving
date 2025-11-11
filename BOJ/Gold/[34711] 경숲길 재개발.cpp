#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define LINF 0x3f3f3f3f3f3f3f3fLL

ll height[64], sum[64];

ll rec(ll x, ll lv) {
  if (x <= 0) return 0;
  while (x <= height[lv-1]) lv--;
  if (x == height[lv]) return sum[lv];
  ll res = lv + rec(height[lv-1], lv-1) + rec(x - height[lv-1] - 1, lv-1);

  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  ll N; cin >> N;

  height[1] = 1; 
  for (int i = 2; i < 64; i++) {
    height[i] = height[i-1] * 2 + 1;
  }

  for (int i = 1; i < 64; i++) {
    sum[i] = sum[i-1] * 2 + i;
  }

  ll idx = 0;
  while (height[idx] < N) {
    idx++;
  }
    
  cout << rec(N, idx) << '\n';
}