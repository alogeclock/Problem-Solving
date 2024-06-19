// idea: binary search

#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define PINF 1000000007

int N, K; // 지면 수, 목표 지면수
int moloco[100005], price[100005];

bool check(int mid) {
  int count = 0;  // 낙찰된다면 count++
  for (int i = 0; i < N; i++) 
    if (moloco[i] + mid >= price[i]) count++;
  return (count >= K);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N >> K;

  for (int i = 0; i < N; i++) cin >> moloco[i] >> price[i];

  // F-T 문제, last가 모든 범위 훑도록
  int first = -1, last = 1000000000;
  while (first + 1 < last) {
    int mid = (first + mid) / 2;
    if (check(mid)) first = mid;
    else last = mid;
  }

  cout << last;
}