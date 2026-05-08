#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define point pair<ll, ll>
#define line pair<point, point>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

/**
 * i번째 이동에서 양수 방향 또는 음수 방향으로 이동한다. 0을 통과하는 최대 수는?
 * 이 문제의 제약사항에서, 어떤 이동도 0에서 끝나지 않는다. 모든 입력 변수는 정수이다.
 */

ll N;
vector<ll> moves;

ll rec(ll pass_count, double coord, ll tries)
{
    if (tries == N) return pass_count;

    double coord_pos = coord + moves[tries];
    double coord_neg = coord - moves[tries];
    ll pass_count_pos = pass_count;
    ll pass_count_neg = pass_count;

    if (coord_pos / abs(coord_pos) * coord / abs(coord) < 0.0)
        pass_count_pos = pass_count + 1;

    if (coord_neg / abs(coord_neg) * coord / abs(coord) < 0.0)
        pass_count_neg = pass_count + 1;

    return max(rec(pass_count_pos, coord_pos, tries + 1), rec(pass_count_neg, coord_neg, tries + 1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        ll x; cin >> x; moves.push_back(x);
    }
    
    cout << rec(0, 0.5, 0) << endl;
}