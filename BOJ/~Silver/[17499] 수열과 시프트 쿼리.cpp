#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll v[200200];
int main() {
  ll N, Q; cin >> N >> Q;
  
  for (int i = 0; i < N; i++) cin >> v[i];

  ll s = 0, len = N - 1;
  for (int i = 0; i < Q; i++) {
    ll op; cin >> op;
    
    if (op == 1) {
      ll idx, weight; cin >> idx >> weight;
      idx = (s + idx - 1) % N;
      v[idx] += weight;
    }
    else if (op == 2) {
      ll shift; cin >> shift;
      s = (s - shift) % N;
      if (s < 0) s += N;
    }
    else if (op == 3) {
      ll shift; cin >> shift;
      s = (s + shift) % N;
    }
  }
  
  for (int i = s; i < N; i++)
    cout << v[i] << ' ';
  for (int i = 0; i < s; i++)
    cout << v[i] << ' ';
}
