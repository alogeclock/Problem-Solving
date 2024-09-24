#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007LL

void Swap(vector<ll> &v, ll i, ll j) {
  ll temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

ll Partition(vector<ll> &v, ll s, ll e) {
  ll x = v[e], i = s - 1;
  for (ll j = s; j < e; j++) {
    if (v[j] <= x) Swap(v, ++i, j);
  }
  Swap(v, i + 1, e);
  return i + 1;
}

void QuickSort(vector<ll> &v, ll s, ll e) {
  if (s < e) {
    ll q = Partition(v, s, e);
    QuickSort(v, s, q - 1);
    QuickSort(v, q + 1, e);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0); 

  vector<ll> v = {3, 4, 10, 2, 5, 9, 1, 8, 6, 7};
  
  for (auto i : v) cout << i << ' ';
  cout << '\n';

  QuickSort(v, 0, 9);
  
  for (auto i : v) cout << i << ' ';
}