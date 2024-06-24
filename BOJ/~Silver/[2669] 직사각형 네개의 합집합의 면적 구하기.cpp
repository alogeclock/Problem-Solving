#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007
#define pii pair<int, int>
#define pll pair<ll, ll>

int m[201][201];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	for (int i = 0; i < 4; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		for (int y = 2 * a; y < 2 * c; y++) {
			for (int x = 2 * b; x < 2 * d; x++) {
				m[x][y] = 1;
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < 200; i+= 2) {
		for (int j = 0; j < 200; j+= 2) {
			if (m[i][j] && m[i + 1][j + 1] && m[i][j + 1] && m[i + 1][j]) sum++;
		}
	}

	cout << sum;
}