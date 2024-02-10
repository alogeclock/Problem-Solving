#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e5 + 1)

int arr[MAX_NUM];
int N, M;

// mid: 카드팩에 구성해야 하는 최대 카드 수
bool Check(int mid) {
  int cur = 0, pack = 0;
  map<int, int> m;

  // rp가 끝에 도달 시, maxCard는 이미 구해짐
  for (int lp = 0, rp = 0; rp < N;) {
    if (m[arr[rp]] == 0) {
      m[arr[rp]]++;
      rp++;
      cur++;
      if (cur == mid) {  // 카드팩 구성 성공
        pack++;
        lp = rp;
        cur = 0;
        m.clear();
      }
    } else {  // 중복 방지
      while (m[arr[rp]] > 0) {
        m[arr[lp]]--;
        lp++;
        cur--;
      }
    }
  }

  return pack >= M;  // 요구한 카드 수로 카드팩을 구성하는 데 성공했는지 판별
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;  // 카드 수, 카드 팩 수

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  int lo = 1, hi = (N / M) + 1;
  for (; lo + 1 < hi;) {  // T-F 문제
    int mid = (lo + hi) / 2;
    if (Check(mid))  // 요구한 카드 수로 카드팩 구성 시도
      lo = mid;      // 구성 성공: 카드 수를 늘림
    else
      hi = mid;  // 구성 실패: 카드 수를 줄임
  }

  cout << lo << '\n';

  return 0;
}