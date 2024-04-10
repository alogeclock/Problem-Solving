#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define PINF 1000000007

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<int> A(N), B(N);

  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i], B[i] *= -1;

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  int sum = 0;
  for (int i = 0; i < N; i++) sum += A[i] * (-B[i]);

  cout << sum;

  return 0;
}