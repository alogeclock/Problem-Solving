#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM 1000001
#define notInitalValue(x) arr[x] != -1e9

int arr[MAX_NUM];  // arr[0]은 무시

void sieve() {
  for (int i = 1; i < MAX_NUM; i++) {
    if (notInitalValue(i)) {  // 초기값이 아니라면
      int cnt = 0;
      for (int j = i; j < MAX_NUM; j += i)
        if (notInitalValue(j)) {
          arr[j]--;
          cnt++;
        }
      arr[i] += cnt;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;  // 플레이어의 수
  cin >> N;

  fill(arr, arr + MAX_NUM, -1e9);

  queue<int> q;

  for (int i = 0; i < N; i++) {
    int input;
    cin >> input;
    q.push(input);
    arr[input] = 0;
  }

  sieve();

  while (q.size()) {
    cout << arr[q.front()] << ' ';
    q.pop();
  }

  cout << '\n';

  return 0;
}