#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007

ll vst[1000];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  // 1000까지의 소수 계산
  vector<ll> prime;  
  for (int i = 2; i < 1000; i++) {
    if (vst[i]) continue;
    prime.push_back(i); 
    for (int j = i; j < 1000; j += i)
      vst[j] = 1;
  }


  ll N; string s;
  while (cin >> N) {
    if (N == 0) break;
    cout << N << " = ";
    
    string s = "";
    string token;
    while (N) {
      ll result = 1;
      for (auto i : prime) {
        if (result * i <= N) result *= i;
        else {
          if (N / result != 0) token = to_string(N / result);
          else token = "1";

          for (auto j : prime) {
            if (i == j) break;
            token += '*' + to_string(j);
          }

          N = N % result;
          break;
        }
      }
      
      if (N > 0) s = " + " + token + s;
      else s = token + s;
    }
    
    cout << s << '\n';
  }
}