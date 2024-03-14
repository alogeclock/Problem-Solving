#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define PINF 1000000007

int priority[55];
bool switch_on[55];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N, K;
  cin >> N >> K;

  priority_queue<pair<int, int>> pq;
  for (int i = 0; i < N; i++) {
    cin >> priority[i];
    pq.push({priority[i], i});
  }

  for (int i = 0; i < K; i++) {
    int idx = -1;
    if (pq.size()) {
      idx = pq.top().second;
      switch_on[idx] = true;
      pq.pop();
    }
    cout << idx + 1 << '\n';
  }

  for (int i = 0; i < N; i++) {
    if (switch_on[i])
      cout << i + 1 << '\n';
    else
      cout << 0 << '\n';
  }
}