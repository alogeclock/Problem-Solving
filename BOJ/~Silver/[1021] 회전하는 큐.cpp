// idea: deque

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007

ll Left(deque<ll> dq, ll idx) {
  ll count = 0;
  while (dq.front() != idx) dq.pop_front(), count++;
  return count;
}

ll Right(deque<ll> dq, ll idx) {
  ll count = 0;
  while (dq.front() != idx) {
    ll val = dq.back();
    dq.pop_back(), dq.push_front(val), count++;
  }
  return count;
}

void LeftRef(deque<ll> &dq, ll idx) {
  while (dq.front() != idx) {
    ll val = dq.front();
    dq.pop_front(), dq.push_back(val);
  }
  dq.pop_front();
}

void RightRef(deque<ll> &dq, ll idx) {
  while (dq.front() != idx) {
    ll val = dq.back();
    dq.pop_back(), dq.push_front(val);
  }
  dq.pop_front();
}

// debugging function
void PrintDeque(deque<ll> dq, ll idx, ll lp, ll rp) {
  cout << "lp, rp: " << lp << ' ' << rp << ", delete " << idx << ": ";
  while (dq.size()) {
    cout << dq.front() << ' ';
    dq.pop_front();
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll N, M; cin >> N >> M; // queue size, number of idx
  deque<ll> dq;
  for (ll i = 1; i <= N; i++) dq.push_back(i);

  ll ans = 0;
  while (M--) {
    ll idx; cin >> idx;
    ll lp = Left(dq, idx), rp = Right(dq, idx);

    if (lp < rp) ans += lp, LeftRef(dq, idx);
    else ans += rp, RightRef(dq, idx);
    // PrintDeque(dq, idx, lp, rp);
  }

  cout << ans;
}