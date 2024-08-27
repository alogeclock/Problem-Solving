// idea: KMP
// 1. 접두/접미사의 실패 테이블을 만들어, 초반부가 같은 곳까지 점프하기

/*
[실패 테이블의 의미] 
패턴이 'abaca' 일 때, 원본 문자열이 'aba'까지 맞췄다면, 4번째 원본 문자열에서 'b'가 나와서 틀렸더라도 'a'까지는 맞춘 거나 다름없음. 따라서 패턴의 첫 번째(=a)로 돌아가서 다시 검사하는 게 아니라, 이미 맞춘 'a'의 다음 글자인 'b'를 검사함.

s: ababakfa
p: abaca
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007LL

vector<ll> fail(string p) { // 실패 테이블 생성 함수
  ll sz = p.size();
  vector<ll> table(sz, 0);
  for (int i = 1, j = 0; i < sz; i++) {
    while (j > 0 && p[i] != p[j]) j = table[j - 1];
    if (p[i] == p[j]) table[i] = ++j;
  }
  return table;
}

bool kmp(string s, string p) {
  vector<ll> table = fail(p);
  for (int i = 0, j = 0; i < s.size(); i++) {
    while (j > 0 && s[i] != p[j]) j = table[j - 1];
    if (s[i] == p[j]) {
      if (j == p.size() - 1) return 1; // 탐색 성공
      else j++;
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string s, p; cin >> s >> p;
  cout << kmp(s, p);
}

// ■ check list ■
// 1. overflow, data type, memset. ==, >=, >
// 2. first visit, % MOD