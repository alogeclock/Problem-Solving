// idea: simple math

#include <iostream>
using namespace std;

int main() {
  long long roomNum;
  long long sum = 1, prev = 1;

  cin >> roomNum;

  while (sum < roomNum) {
    sum += 6 * prev;
    prev++;
  }

  cout << prev << endl;
}