#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define PINF 1000000007

vector<int> g[200005];
bool vst[200005];
bool vst_src[200005];  // 시작 지점으로 입력된 적 있다면 무시

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N, M, Q;
  cin >> N >> M >> Q;  // vertex, edge, pizza

  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  for (int i = 0; i < Q; i++) {
    int pizza;  // 피자를 준 집
    cin >> pizza;

    int love = 0;

    if (vst_src[pizza]) {
      cout << 0 << '\n';
      continue;
    }

    if (!vst[pizza]) {
      vst[pizza] = true;
      vst_src[pizza] = true;
      love++;
    }

    for (auto next : g[pizza]) {
      if (!vst[next]) {
        love++;
        vst[next] = true;
      }
    }

    cout << love << '\n';
  }
}
