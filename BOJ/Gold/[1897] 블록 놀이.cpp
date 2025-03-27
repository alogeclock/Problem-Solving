#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007

string dict[1010], ans;
ll vst[1010];

bool check(string next, string cur) {
  if (next.length() != cur.length() + 1) return false;
  ll c = 0;
  for (auto i : next) {
    if (cur[c] == i) c++;
    if (c == cur.length()) return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll N; cin >> N;
  string word; cin >> word; // 처음 말한 단어
  for (int i = 0; i < N; i++) {
    cin >> dict[i];
    if (dict[i] == word) vst[i] = 1;
  }
  ans = word;
    
  queue<string> q; q.push(word);
  while (!q.empty()) {
    string cur = q.front();
    q.pop();
    for (int i = 0; i < N; i++) {
      string next = dict[i];
      if (!vst[i] && check(next, cur)) {
        if (ans.length() < next.length()) ans = next;
        vst[i] = 1;
        q.push(next);
      }
    }
  }
  cout << ans;
}