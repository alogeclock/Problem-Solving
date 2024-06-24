#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007
#define pii pair<int, int>
#define pll pair<ll, ll>

int arr[110], nset[110]; // 뽑힌 정수들을 저장하는 배열
int ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int N; cin >> N;
  for (int i = 1; i <= N; i++) cin >> arr[i];

  for (int i = 1; i <= N; i++) {
    if (nset[i] == 1) continue;
    vector<int> v; v.push_back(i);

    int flag = 0;
    while (1) {
      int cur = arr[v.back()];
      for (int j = 0; j < v.size(); j++) {
        if (v[j] == cur) {
          if (i == cur) flag = 1;
          goto EXIT;
        }
      }
      v.push_back(cur);
    }
    
    EXIT:
    if (flag) {
      for (auto k : v) { // 벡터의 모든 원소 뽑기
        nset[k] = 1; ans++;
      }
    }
  }
  
  cout << ans << '\n';
  for (int i = 1; i <= N; i++) {
    if (nset[i]) cout << i << '\n';
  }
}