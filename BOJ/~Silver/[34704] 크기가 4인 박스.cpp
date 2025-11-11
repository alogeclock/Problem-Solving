#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define LINF 0x3f3f3f3f3f3f3f3fLL

ll box[5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    ll N; cin >> N;
    for (int i = 0; i < N; i++) {
        ll x; cin >> x; box[x]++;
    }

    ll ans = box[4];
    while (box[3] > 0 && box[1] > 0) {
        ans++;
        box[3]--;
        box[1]--;
    }
    ans += box[3];
    ans += (box[1] + 2 * box[2]) / 4;
    if ((box[1] + 2 * box[2]) % 4 != 0)
        ans++;

    cout << ans;
}