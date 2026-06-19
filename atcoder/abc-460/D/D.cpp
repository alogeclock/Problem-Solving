// Repeatedly Repainting
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

vector<vector<ll>> M;
vector<vector<ll>> NM;
vector<vector<ll>> vst;

const ll dh[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const ll dw[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll H, W; cin >> H >> W;

    M.resize(H + 1, vector<ll>(W + 1));
    NM.resize(H + 1, vector<ll>(W + 1));
    vst.resize(H + 1, vector<ll>(W + 1));

    queue<tuple<ll, ll, ll>> q;
    queue<tuple<ll, ll, ll>> nq;

    for (ll i = 1; i <= H; ++i)
    {
        string s; cin >> s;

        for (ll j = 1; j <= W; ++j)
        {
            if (s[j - 1] == '#') 
            {
                M[i][j] = 1;
                vst[i][j] = 1;
                q.push({i, j, 0});
            }
            else 
            {
                M[i][j] = 0;
            }
        }
    }

    // 1회 조작을 실제로 수행한다.
    while (q.size())
    {
        auto [ch, cw, cdst] = q.front();
        q.pop();

        for (ll i = 0; i < 8; i++)
        {
            ll nh = ch + dh[i];
            ll nw = cw + dw[i];

            if (nh <= 0 || nh > H || nw <= 0 || nw > W) continue;
            if (vst[nh][nw]) continue;

            NM[nh][nw] = 1;
            vst[nh][nw] = 1;
            nq.push({nh, nw, 0});
        }
    }

    for (ll h = 1; h <= H; ++h)
    {
        for (ll w = 1; w <= W; ++w)
        {
            if (NM[h][w]) vst[h][w] = 0;
            else vst[h][w] = LINF;
        }
    }

    // edge-case early-return
    if (nq.empty())
    {
        for (ll h = 1; h <= H; ++h)
        {
            for (ll w = 1; w <= W; ++w)
            {
                cout << '.';
            }
            cout <<'\n';
        }

        return 0;
    }

    while (nq.size())
    {
        auto [ch, cw, cdst] = nq.front();
        nq.pop();        

        for (ll i = 0; i < 8; i++)
        {
            ll nh = ch + dh[i];
            ll nw = cw + dw[i];
            ll ndst = cdst + 1;

            if (nh <= 0 || nh > H || nw <= 0 || nw > W) continue;
            if (ndst >= vst[nh][nw]) continue;

            vst[nh][nw] = ndst;
            nq.push({nh, nw, ndst});
        }
    }

    for (ll h = 1; h <= H; ++h)
    {
        for (ll w = 1; w <= W; ++w)
        {
            if (vst[h][w] % 2) cout << '#';
            else cout << '.';
        }
        cout << '\n';
    }
}
