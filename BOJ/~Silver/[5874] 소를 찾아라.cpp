#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

	string s; cin >> s;
	ll back = 0;
	string prev, cur;
	
	ll ans = 0;
	for (int i = 1; i < s.size(); i++) {
		prev = s[i - 1], cur = s[i];
		if (prev + cur == "((") back++;
		else if (prev + cur == "))") ans += back;
	}

	cout << ans;
}