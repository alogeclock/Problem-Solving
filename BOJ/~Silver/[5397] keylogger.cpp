// idea: linked list STL

/*
  If we erase one elements in linked-list, iterator do not know the address of the previous element. So iterator should get the return values of erase(iterator) function to know the address of linked values(which is linked to erased value). 

  erase(iterator) function returns iterator which points next element of linked list. iterator--, iterator++ operator overloadings are also similar to node->next, node->prev in linked-list of C.
*/

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

  ll T; cin >> T;

  while (T--) {
    string s; cin >> s;
    list<char> L; list<char>::iterator it = L.end();

    for (auto c : s) {
      if (c == '-') { if (it != L.begin()) it = L.erase(--it); }
      else if (c == '<') { if (it != L.begin()) it--; }
      else if (c == '>') { if (it != L.end()) it++; }
      else L.insert(it, c);
    }

    for (auto it : L) cout << it;
    cout << '\n';
  }
}