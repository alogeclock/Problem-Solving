// The Honest Woodcutters
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define point pair<ll, ll>
#define line pair<point, point>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

ll A[101], B[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N;
    cin >> N;

    for (ll i = 1; i <= N; ++i)
    {
        cin >> A[i];
    }

    for (ll i = 1; i <= N; ++i)
    {
        cin >> B[i];
    }

    bool flag = true;
    for (ll i = 1; i <= N; ++i)
    {
        if (B[A[i]] != i) flag = false;
    }

    flag ? cout << "Yes\n" : cout << "No\n";
}
