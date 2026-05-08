#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define point pair<ll, ll>
#define line pair<point, point>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

// B - Sensor Data Logging
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T, X; cin >> T >> X;

    ll last = 0;
    for (int i = 0; i <= T; i++)
    {
        ll x; cin >> x;
        if (i == 0)
        {
            cout << i << ' ' << x << '\n';
            last = x;
        }
        else if (abs(last - x) >= X)
        {
            cout << i << ' ' << x << '\n';
            last = x;
        }
    }
}
