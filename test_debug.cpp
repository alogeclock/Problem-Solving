#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007

string dict[1010];
ll vst[1010];

bool overlap(string s, string t) {
  if (t.length() != s.length() + 1) return false;
  int c = 0; // 처음 말한 단어의 c번째 문자
  for (auto i : t) {
    if (s[c] == i) c++;  
    if (c == s.length()) return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll N; cin >> N;
  string word; cin >> word;
  for (int i = 0; i < N; i++) {
    cin >> dict[i];
    if (dict[i] == word) vst[i] = 1;
  }

  queue<string> q; q.push(word);
  string ans = word;
  while (q.size()) {
    string cur = q.front(); q.pop();
    for (int i = 0; i < N; i++) {
      if (vst[i]) continue;
      string next = dict[i];
      if (overlap(cur, next)) {
        q.push(next);
        if (ans.length() > next.length()) ans = next;
        vst[i] = 1;
      }
    }
  }
  cout << ans;
}