// [Bronze 1] 1003. 줄 세우기
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

    ll N; cin >> N;
    vector<ll> v;

    for (int i = 1; i <= N; i++)
    {
        ll x; cin >> x; v.insert(v.begin() + x, i);
    }
    
    reverse(v.begin(), v.end());

    for (auto x : v)
    {
        cout << x << ' ';
    }
}
