#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define point pair<ll, ll>
#define line pair<point, point>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T;
    cin >> T;

    while (T--)
    {
        ll x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        ll dx = x2 - x1;
        ll dy = y2 - y1;
        ll dist = dx * dx + dy * dy;

        bool f1 = (r2 - r1) * (r2 - r1) <= dist;
        bool f2 = (r2 + r1) * (r2 + r1) >= dist;

        (f1 && f2) ? cout << "Yes\n" : cout << "No\n";
    }
}
