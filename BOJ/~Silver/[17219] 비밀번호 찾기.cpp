// idea: hashmap

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  ll N, M; cin >> N >> M;
  map<string, string> m;
  for (int i = 0; i < N; i++) {
    string s, t;  cin >> s >> t;
    m[s] = t;
  }

  for (int i = 0; i < M; i++) {
    string s; cin >> s;
    cout << m[s] << '\n';
  }
}