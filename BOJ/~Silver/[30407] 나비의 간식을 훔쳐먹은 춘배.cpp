#include <bits/stdc++.h>
using namespace std;

int totalPunch, hp, dst, cDst;
int damage[20];

int dp(int _punch, int _dst, int _hp, int _surprise) {
  if (_punch == totalPunch)
    return _hp;
  if (_hp <= 0)
    return -1;

  // 춘배가 현재 거리일 때의 데미지
  int _damage = min(0, _dst - damage[_punch]);
  // 웅크리기, 걷기, 놀라게 하기
  int ret = -1e9;

  // 이전 턴에 놀라게 하기를 사용했을 경우
  if (_surprise == 0) {
    _surprise = -1;
    _damage = 0;
  }

  // 웅크리기
  ret = max(ret, dp(_punch + 1, _dst, _hp + (_damage / 2), _surprise));

  // 걷기: 걸어간 만큼 데미지가 감소됨(hp가 늘지 않도록 min 처리)
  ret = max(ret, dp(_punch + 1, _dst + cDst, _hp + min(0, cDst + _damage),
                    _surprise));

  // 놀라게 하기
  if (_surprise == 1)
    ret = max(ret, dp(_punch + 1, _dst, _hp + _damage, 0));

  if (ret <= 0)
    ret = -1;

  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> totalPunch;
  cin >> hp >> dst >> cDst;

  for (int i = 0; i < totalPunch; i++)
    cin >> damage[i];

  cout << dp(0, dst, hp, 1);

  return 0;
}