// idea: stack

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007

struct Score {
  ll idx, score, three, two;
  bool operator<(Score next) { // 오름차순 정렬
    if (score == next.score) {
      if (three == next.three)
        return two > next.two;
      return three > next.three;
    }
    return score > next.score;
  }
};

Score score[3];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll N; cin >> N;
  score[0].idx = 1, score[1].idx = 2, score[2].idx = 3;

  while (N--) {
    for (ll i = 0; i < 3; i++) {
      ll point; cin >> point;
      score[i].score += point;
      if (point == 3) score[i].three++;
      else if (point == 2) score[i].two++;
    }
  }

  sort(score, score + 3);

  if (score[0].score == score[1].score && score[0].three == score[1].three && score[0].two == score[1].two) cout << 0 << ' ' << score[0].score; 
  else cout << score[0].idx << ' ' << score[0].score;
}