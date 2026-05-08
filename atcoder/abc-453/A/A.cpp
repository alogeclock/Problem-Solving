#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define point pair<ll, ll>
#define line pair<point, point>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

// A - Trimo
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll N; cin >> N;
    string S; cin >> S;

    bool found_non_o = false; // 'o'가 아닌 문자를 찾았는지 여부
    for (auto i : S)
    {
        if (!found_non_o && i == 'o')
            continue;

        found_non_o = true;
        cout << i;
    }

    cout << endl;
}