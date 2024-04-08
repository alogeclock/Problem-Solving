
#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define PINF 1000000007
#define pii pair<int, int>

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int input = 1, cnt = 0;
	int arr[20];
	while (true) {
		cin >> input;
		arr[cnt++] = input;
		if (input == 0) {
			int ans = 0;
			cnt--;
			sort(arr, arr + cnt);
			for (int i = 0; i < cnt; i++) {
				for (int j = 0; j < cnt; j++) {
					if (arr[j] == arr[i] * 2) ans++;
				}
			}
			cout << ans << '\n';
			memset(arr, 0, sizeof(arr));
			cnt = 0;
		}
		if (input == -1) break;
	}
}
