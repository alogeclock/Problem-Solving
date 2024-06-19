#include <iostream>
using namespace std;

int main() {
  long long total;
  int types, item, num;

  cin >> total;
  cin >> types;

  long long sum = 0;
  for (int i = 0; i < types; i++) {
    cin >> item >> num;
    sum += item * num;
  }

  if (total == sum)
    cout << "Yes\n";
  else
    cout << "No\n";

  return 0;
}