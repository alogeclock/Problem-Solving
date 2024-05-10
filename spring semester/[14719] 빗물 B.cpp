// idea: 옆으로 주어졌다고 항상 옆으로 고려하지 않는다. 위에서부터 고려

#include <bits/stdc++.h>
using namespace std;
#define BLOCK 1
#define WATER -1

int m[500][500];
int block[500];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int height, width;
  cin >> height >> width;
  for (int i = 0; i < width; i++) {
    cin >> block[i];
    for (int j = 0; j < block[i]; j++)
      m[i][j] = BLOCK;
  }

  // 위에서부터 내려오면서 물을 채움
  int ans = 0;
  for (int h = height - 1; h >= 0; h--) {
    int prev = -1;
    for (int w = 0; w < width; w++) {
      if (m[w][h] == BLOCK) {
        if (prev != -1)
          while (prev < w)
            m[prev++][h] = WATER, ans++;
        prev = w + 1;
      }
    }
  }

  cout << ans;
}