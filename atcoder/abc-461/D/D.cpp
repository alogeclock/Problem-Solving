// Count Subgrid Sum = K
// idea: 2D Prefix Sum, 1D Compression, Prefix Frequency
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define point pair<ll, ll>
#define line pair<point, point>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

ll M[505][505];
ll PS[505][505]; // 2D Prefix of Sum
ll freq[250250];

ll Solve2DPrefixSum(ll ch, ll nh, ll cw, ll nw)
{
    return PS[nh][nw] - PS[ch - 1][nw] - PS[nh][cw - 1] + PS[ch - 1][cw - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll H, W, K;
    cin >> H >> W >> K;

    for (ll i = 1; i <= H; i++)
    {
        string s;
        cin >> s;
        for (ll j = 1; j <= W; j++)
        {
            M[i][j] = s[j - 1] - '0';
            PS[i][j] += PS[i][j - 1] + PS[i - 1][j] - PS[i - 1][j - 1] + M[i][j];
        }
    }

    ll ans = 0;
    for (ll ch = 1; ch <= H; ch++)
    {
        for (ll nh = ch; nh <= H; nh++)
        {
            ll prefix = 0;
            freq[0] = 1;

            for (ll w = 1; w <= W; w++)
            {
                prefix += Solve2DPrefixSum(ch, nh, w, w);
                if (prefix >= K)
                {
                    ans += freq[prefix - K];
                }
                freq[prefix]++;
            }

            // reset
            prefix = 0;
            freq[0] = 0;

            for (ll w = 1; w <= W; w++)
            {
                prefix += Solve2DPrefixSum(ch, nh, w, w);
                freq[prefix] = 0;
            }
        }
    }

    cout << ans << '\n';
}
