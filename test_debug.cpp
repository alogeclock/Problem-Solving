// idea: deque

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  // 고찰 1: 완전탐색, 
  // 모든 블록 높이 N에 대해 오른쪽으로 왼쪽으로 이동해서 직사각형 찾아봄
  // 고찰 2: 완전탐색의 이분탐색
  // 모든 블록 높이 N에 대해 이분 탐색으로 시작부분과 끝부분을 찾아봄.
  // 문제점: 이분 탐색처럼 F-T, T-F가 깔끔하게 나뉘지 않음, F-T가 번갈아 나옴

  // 어떤 막대기에 대해 좌우로 탐색하겠다는 고찰은 필요해 보인다.
}