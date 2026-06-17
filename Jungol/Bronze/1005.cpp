// [Bronze 2] 1005. 가장 큰 소인수
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define point pair<ll, ll>
#define line pair<point, point>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

ll sieve[50050];
vector<ll> prime;

void Sieve()
{
    for (int i = 2; i <= 50000; i++)
    {
        if (sieve[i]) 
        {
            continue;
        }

        prime.push_back(i);

        for (int j = i * 2; j <= 50000; j += i)
        {
            sieve[j] = 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Sieve(); // erathosthenes's sieve

    ll N; cin >> N;

    ll largest_prime_factor = -1;
    ll largest_lpf_number = -1;
    while (N--)
    {
        ll x; cin >> x;
        if (x == 1) continue;

        ll max_factor = -1;
        for (auto factor : prime)
        {
            if (x <= factor) break;
            
            if (x % factor == 0) 
            {
                max_factor = std::max(factor, max_factor);
            }
        }

        if (largest_prime_factor < max_factor)
        {
            largest_prime_factor = max_factor;
            largest_lpf_number = x;
        }
    }

    cout << largest_lpf_number;
}
