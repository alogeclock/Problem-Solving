#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define PINF 1000000007
#define pii pair<int, int>

int arr[105];
int change[105];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N, M;
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    arr[i] = i + 1;
    change[i] = arr[i];
  }

  for (int i = 0; i < M; i++) {
    int begin, end, mid;
    cin >> begin >> end >> mid;

    begin--, mid--, end--;

    for (int i = 0; i <= end - mid; i++) change[begin + i] = arr[mid + i];

    for (int i = 0; i < mid - begin; i++)
      change[begin + (end - mid) + i + 1] = arr[begin + i];

    for (int i = 0; i < N; i++) arr[i] = change[i];
  }

  for (int i = 0; i < N; i++) cout << arr[i] << ' ';
}
