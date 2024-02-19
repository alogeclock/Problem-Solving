#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM ((int)1e6 + 5)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF ((int)1e9 + 7)
#define ll long long

struct Tree {
  char left_child, right_child;
};

map<char, Tree> g;

void preorder(char i) {
  cout << i;
  if (g[i].left_child != '.') preorder(g[i].left_child);
  if (g[i].right_child != '.') preorder(g[i].right_child);
}

void inorder(char i) {
  if (g[i].left_child != '.') inorder(g[i].left_child);
  cout << i;
  if (g[i].right_child != '.') inorder(g[i].right_child);
}

void postorder(char i) {
  if (g[i].left_child != '.') postorder(g[i].left_child);
  if (g[i].right_child != '.') postorder(g[i].right_child);
  cout << i;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    char u, v, w;
    cin >> u >> v >> w;
    g[u].left_child = v, g[u].right_child = w;
  }

  preorder('A'), cout << '\n';
  inorder('A'), cout << '\n';
  postorder('A'), cout << '\n';

  return 0;
}