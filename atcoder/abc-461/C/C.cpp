// Variety
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

vector<pll> gems;
ll colors[200200];
bool vst[200200];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N, K, M;
    cin >> N >> K >> M;
    for (ll i = 0; i < N; ++i)
    {
        ll c, x;
        cin >> c >> x;
        gems.push_back({ c, x });
    }

    sort(gems.begin(), gems.end(), [](const pll& a, const pll& b)
         { return a.second > b.second; });

    map<ll, ll> color_reference_map;
    ll selects = 0;
    ll colors = 0;
    ll sum = 0;

    // 첫 번째 선택: 색깔별로 1개씩 가장 큰 보석 K개까지 선택
    for (ll i = 0; i < N; ++i)
    {
        auto [c, v] = gems[i];

        if (color_reference_map[c] == 0)
        {
            color_reference_map[c]++;
            selects++;
            colors++;
            sum += v;
            vst[i] = true;
        }

        if (colors == M)
        {
            break;
        }
    }

    // 두 번째 선택: 비싼 순서대로 안 고른 보석 선택
    for (ll i = 0; i < N; ++i)
    {
        if (selects == K) break;
        if (vst[i]) continue;

        auto [c, v] = gems[i];
        selects++;
        sum += v;
    }

    cout << sum << '\n';
}