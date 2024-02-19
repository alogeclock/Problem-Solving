#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF ((int)1e9 + 7)
#define ll long long

int arr[1010], lis[1010];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;
  memset(lis, 0x3f, sizeof(lis));

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    int idx = lower_bound(lis, lis + N + 5, arr[i]) - lis;
    if (lis[idx] > arr[i]) lis[idx] = arr[i];
  }

  cout << lower_bound(lis, lis + N + 5, INF) - lis;
  return 0;
}