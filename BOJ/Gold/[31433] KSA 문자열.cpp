#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007

string ksa;
int len;

int solve(string s) {
  int count = 0, size = s.size();
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != ksa[i - count]) {
      count++; size--;
    }
  }

  return count + abs(len - size);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s; cin >> s;
    len = s.size();
  
    for (int i = 0; i < s.size(); i++) {
        if (i % 3 == 0) ksa += 'K';
        if (i % 3 == 1) ksa += 'S';
        if (i % 3 == 2) ksa += 'A';
    }
    
    // 문자열 순회하며 삭제, count: s가 ksa와 문자열이 달랐던 횟수
    int ans = min(solve(s), INF);
    ans = min(solve("K" + s) + 1, ans);
    ans = min(solve("KS" + s) + 2, ans);

    cout << ans;
}