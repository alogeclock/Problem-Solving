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
	int cnt = 0, front = 0, back = 0;
	for (auto i : s) {
		if (cnt < s.size() / 2) front += i - '0';
		else back += i - '0';
		cnt++;
	}

	(front == back) ? cout << "LUCKY" : cout << "READY";
}