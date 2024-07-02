#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007

int numbers[10];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string s; cin >> s;

  for (auto i : s) {
    int k = i - '0';
    if (k == 6 && numbers[6] > numbers[9]) numbers[9]++;
    else if (k == 9 && numbers[9] > numbers[6]) numbers[6]++;
    else numbers[k]++;
  }

  cout << *max_element(numbers, numbers + 10);

  return 0;
}