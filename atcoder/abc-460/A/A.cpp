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

    ll base = N % M;
    ll count = 1;
    while (base > 0)
    {
        base = N % base;
        count++;
    }

    cout << count << '\n';
}
