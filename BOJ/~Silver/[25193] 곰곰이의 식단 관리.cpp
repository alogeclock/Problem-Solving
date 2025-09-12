#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

	ll N; cin >> N;
	string s; cin >> s;

	double chicken = 0, food = 0;
	for (auto i : s) {
		(i == 'C') ? chicken++ : food++;
	}

	cout << ceil(chicken / (food + 1.0));
}