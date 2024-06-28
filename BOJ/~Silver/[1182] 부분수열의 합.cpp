// idea: brute-force

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007

int N, S, cnt, arr[20];

void dfs(int k, vector<int> seq) {
  if (k >= N) {
    if (seq.empty()) return;
    int sum = 0;
    for (auto i : seq) sum += arr[i];
    if (sum == S) cnt++;
    return;
  }
  
  dfs(k + 1, seq); // 수열에 입력하지 않고 dfs
  seq.push_back(k);
  dfs(k + 1, seq); // 수열에 입력한 뒤 dfs
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> N >> S;
  for (int i = 0; i < N; i++) cin >> arr[i];

  vector<int> initial_seq;
  dfs(0, initial_seq);
  cout << cnt;
}