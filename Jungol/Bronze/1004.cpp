// [Bronze 3] 1004. 합과 평균 표준편차
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define point pair<ll, ll>
#define line pair<point, point>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

void Print(double x) 
{
    ll y = round(x * 10.0);
    if (y % 10 == 0)
    {
        cout << y / 10 << '\n';
    }
    else
    {
        cout << y / 10 << "." << (y % 10) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N; cin >> N;

    vector<ll> v;
    ll sum = 0;
    double avg = 0;
    for (int i = 0; i < N; i++)
    {
        ll x; cin >> x; v.push_back(x);
        sum += x;
    }

    avg = (double)sum / N;

    double standard_deviation = 0;
    for (int i = 0; i < N; i++)
    {
        standard_deviation += pow(v[i] - avg, 2);
    }
    standard_deviation = sqrt(standard_deviation / N);

    cout << sum << '\n';
    Print(avg);
    Print(standard_deviation);
}
