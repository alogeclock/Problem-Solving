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

    ll N, M;
    cin >> N >> M;

    priority_queue<ll, vector<ll>, less<ll>> A;
    priority_queue<ll, vector<ll>, less<ll>> B;

    for (ll i = 1; i <= N; ++i)
    {
        ll x; cin >> x; A.push(x);
    }

    for (ll i = 1; i <= M; ++i)
    {
        ll x; cin >> x; B.push(x);
    }

    ll ans = 0;
    while (A.size())
    {
        ll curA = A.top();
        A.pop();

        while (B.size())
        {
            ll curB = B.top();
            B.pop();

            if (curA * 2 >= curB)
            {
                ans++;
                break;
            }
        }
    }

    cout << ans << '\n';
}
