#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define PINF 1000000007

int arr[500005];

bool Check(int mid, int val) { return arr[mid] > val; }

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];

  sort(arr, arr + N);

  int M;
  cin >> M;

  for (int i = 0; i < M; i++) {
    int val, lp = 0, rp = N;
    cin >> val;
    while (lp + 1 < rp) {
      int mid = (lp + rp) / 2;
      (Check(mid, val)) ? rp = mid : lp = mid;
    }
    cout << (arr[lp] == val) << ' ';
  }

  return 0;
}