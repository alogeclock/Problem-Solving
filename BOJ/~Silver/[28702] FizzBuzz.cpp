// idea: implement

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  ll num = 0;
  for (int i = 0; i < 3; i++) {
    string s; cin >> s;
    if (s == "FizzBuzz" || s == "Fizz" || s == "Buzz")
      continue;
    num = stoi(s) + (3-i);
  }

  if (num % 3 == 0 && num % 5 == 0)
    cout << "FizzBuzz";
  else if (num % 3 == 0)
    cout << "Fizz";
  else if (num % 5 == 0)
    cout << "Buzz";
  else
    cout << num;
}