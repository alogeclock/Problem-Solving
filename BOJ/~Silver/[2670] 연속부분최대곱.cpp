#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007
#define pii pair<int, int>
#define pll pair<ll, ll>

double arr[10010];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N; cin >> N;
	
	double ans = -1.0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (i > 0) arr[i] = max(arr[i], arr[i - 1] * arr[i]);
		ans = max(ans, arr[i]);
	}

	cout << fixed << setprecision(3) << ans;
}