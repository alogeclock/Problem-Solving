#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007

struct Point {
  int dst;
  vector<char> seq;
  Point(int d, vector<char> seq) : dst(d), seq(seq) {}
  Point(int d, char s, vector<char> seq) {
    this->dst = d, this->seq = seq;
    this->seq.push_back(s);
  } 
};

int Calculate(vector<char> seq) {
  int value = 4, num[4] = {4, 4, 4, 4}, vst[4] = {-1, -1, -1, -1};
  int order = 0;
  for (int i = 0; i < 3; i++) {
    int cur_vst = vst[i];
    if (seq[i] == '*') {
      num[i] = num[i] * num[i + 1];
      num[i + 1] = num[i];
      vst[i] = i, vst[i + 1] = i;
      order++;
    }
    else if (seq[i] == '/') {
      num[i] = num[i] / num[i + 1];
      num[i + 1] = num[i];
      vst[i] = i, vst[i + 1] = i;
      order++;
    }
    for (int j = 0; j < 4; j++) {
      if (cur_vst != -1 && vst[j] == cur_vst) {
        vst[j] = vst[i];
        num[j] = num[i];
      }
    }

    if (order == 3) return num[i];
  }
  
  for (int i = 0; i < 3; i++) {
    int cur_vst = vst[i + 1];
    if (seq[i] == '+') {
      num[i] = num[i] + num[i + 1];
      num[i + 1] = num[i];
      vst[i] = i, vst[i + 1] = i;
      order++;
    }
    if (seq[i] == '-') {
      num[i] = num[i] - num[i + 1];
      num[i + 1] = num[i];
      vst[i] = i, vst[i + 1] = i;
      order++;
    }

    for (int j = 0; j < 4; j++) {
      if (cur_vst != -1 && vst[j] == cur_vst) {
        vst[j] = vst[i];
        num[j] = num[i];
      }
    }

    if (order == 3) return num[i];
  }

  return -1; // error
}

void Print(vector<char> seq, int N) {
  for (auto i : seq)
    cout << "4 " << i << " ";
  cout << "4 = " << N << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    const char formula[4] = {'+', '-', '*', '/'};

    vector<char> initial_seq;
    queue<Point> q; q.push(Point(0, initial_seq));

    while (q.size()) {
      int cdst = q.front().dst;
      vector<char> seq = q.front().seq;
      q.pop();
      if (cdst == 3) {
        if (Calculate(seq) == N) {
          Print(seq, N);
          goto EXIT;
        }
        continue;
      }

      for (int i = 0; i < 4; i++) {
        q.push(Point(cdst + 1, formula[i], seq));
      }
    }

    cout << "no solution\n";

    EXIT:
    ;
  }
}