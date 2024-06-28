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
  int JAVA = 0, CPP = 0, ERROR = 0; 
  
  if ((s[0] <= 'Z' && s[0] >= 'A') || s[0] == '_') ERROR = 1;
  if (s[s.size() - 1] == '_') ERROR = 1;

  char prev = 0;
  for (auto i : s) {
    if (i == '_') CPP = 1;
    if (i >= 'A' && i <= 'Z') JAVA = 1;
    if (CPP && JAVA) ERROR = 1;
    if (prev == '_' && i == '_') ERROR = 1;
    prev = i;
  }

  if (!JAVA) CPP = 1;
  if (ERROR) {
    cout << "Error!";
    return 0;
  }

  if (CPP) {
    int capital = 0;
    for (auto i : s) {
      if (i == '_') {
        capital = 1;
        continue;
      }
      if (capital) {
        capital = 0;
        i += 'A' - 'a';
      }
      cout << i;
    }
  }

  if (JAVA) {
    for (auto i : s) {
      if (i <= 'Z' && i >= 'A') {
        cout << '_';
        cout << (char)(i - 'A' + 'a');
        continue;
      }
      cout << i;
    }
  }
}