// idea: 모든 값이 고유하고 i, M - i가 유일한 하나의 쌍

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define PINF 1000000007LL

ll N, ans, parent[300300], val[300300];
vector<pll> v[300300];

int
main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for (int i = 2; i <= N; i++)
    cin >> parent[i];
  for (int i = 1; i <= N; i++)
    cin >> val[i];
  // v[k]: k번쨰 노드를 부모로 갖는 [값, 노드 번호] 저장
  for (int i = 2; i <= N; i++)
    v[parent[i]].push_back({ val[i], i });

  priority_queue<pll> tv; // 현재 선택할 수 있는 값
  tv.push({ val[1], 1 });

  while (tv.size()) {
    auto [cv, ci] = tv.top(); // cur_value, cur_index
    tv.pop();
    ans += cv;
    cout << ans << '\n';
    for (auto [nv, ni] : v[ci])
      tv.push({ nv, ni });
  }
}

// ■ check list ■
// 1. overflow, data type, memset. ==, >=, >
// 2. first visit, % MOD