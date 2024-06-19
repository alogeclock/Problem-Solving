// idea: stack, 반복문의 엄밀한 조정

#include <bits/stdc++.h>
using namespace std;

int s[500001];
int top = 0;
long long counter = 0;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;
  int *arr = new int[N];
  for (int i = 0; i < N; i++)
    cin >> arr[i];

  for (int i = 0; i < N; i++) {
    int j = top - 1;
    for (; j > 0; j--)
      if (s[j] > arr[i]) break;
    if (top > 0) counter += top - j;
    while (top > 0 && arr[i] > s[top - 1])
      top--;
    s[top++] = arr[i];
  }

  cout << counter << endl;
  delete[] arr;
}