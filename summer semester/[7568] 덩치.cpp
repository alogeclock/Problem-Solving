// idea: O(n·logn) 방식으로 푼다면?
// sort를 통해 정렬한 뒤 한 번 훑어서
// 이전 값에 비해 덩치가 작다면 i값 부여, 작지 않다면 이전 rank 값 부여

#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define PINF 1000000007

struct Person {
  int height, weight, rank;
  Person() : height(0), weight(0), rank(1){};
};

Person arr[51];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i].weight >> arr[i].height;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) continue;
      if (arr[i].weight < arr[j].weight && arr[i].height < arr[j].height)
        arr[i].rank++;
    }
  }

  for (int i = 0; i < N; i++) cout << arr[i].rank << ' ';
}