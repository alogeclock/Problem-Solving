#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define point pair<ll, ll>
#define line pair<point, point>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007

vector<line> lines;
ll cnt[3030], group[3030];

ll ccw(point p1, point p2, point p3) {
  ll ret = (p2.first - p1.first) * (p3.second - p1.second) - (p2.second - p1.second) * (p3.first - p1.first);
  if (ret == 0) return 0;
  return ret / abs(ret); // 1 or -1 return
}

ll intersect(line l1, line l2) {
  point p1 = l1.first, p2 = l1.second;
  point p3 = l2.first, p4 = l2.second;

  ll p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4); 
  ll p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

  // two lines are colinear
  if (p1p2 == 0 && p3p4 == 0) {
    if (p1 > p2) swap(p2, p1);
    if (p3 > p4) swap(p3, p4);
    return p3 <= p2 && p1 <= p4;
  }

  return p1p2 <= 0 && p3p4 <= 0;
}

ll Find(ll x) {
  if (group[x] == x) return x;
  else return Find(group[x]);
}

void Union(ll x, ll y) {
  x = Find(x);
  y = Find(y);

  group[y] = x;
  cnt[x] += cnt[y];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  ll N; cin >> N;

  for (int i = 0; i < N; i++) {
    point p1, p2;
    cin >> p1.first >> p1.second >> p2.first >> p2.second;
    lines.push_back({p1, p2});
  }

  for (int i = 0; i < N; i++) {
    cnt[i] = 1;
    group[i] = i;
  }

  ll group_cnt = N;
  for (int i = 0; i < N; i++) {
    line cur = lines[i];
    for (int j = i+1; j < N; j++) {
      line next = lines[j];
      if (Find(i) != Find(j) && intersect(cur, next)) {
        Union(i, j);
        group_cnt--;
      }
    }
  }

  ll max_cnt = -1;
  for (int i = 0; i < N; i++) {
    max_cnt = max(max_cnt, cnt[i]);
  }

  cout << group_cnt << '\n' << max_cnt;
}