// idea: stack

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

  string s; cin >> s;

  ll stick = 0; char prev;
  stack<char> st;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') st.push(s[i]);
    else {
      if (s[i - 1] == '(') st.pop(), stick += st.size();
      else st.pop(), stick++;
    }
    prev = s[i];
  }

  cout << stick;
}