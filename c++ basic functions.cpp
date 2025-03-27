#include <bits/stdc++.h>
using namespace std;

int pow(int, int);

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // memset: 가능한 값(0, -1, 0x3f)

  // upper_bound, lower_bound

  int arr[5] = {1, 2, 3, 4, 6};
  auto idx = lower_bound(arr, arr + 5, 4) - arr;  // 크거나 같은 값
  auto idx = upper_bound(arr, arr + 5, 4) - arr;  // 큰 값

  // vector, lambda functions

  vector<int> v(101);
  sort(v.begin(), v.end(), [](const int &a, const int &b) { return a < b; });

  // strings

  string s1, s2, s3;
  cout << "enter int data: " << flush;
  cin >> s1;

  getline(cin, s2, '\n');  // 공백을 기준으로 문자열 입력
  int i = stoi(s1);        // 문자열 → 정수
  s3 = to_string(101);     // 정수 → 문자열
  s1.compare("hello\n");   // 같으면 0, 다르면 -1
  cout << "i: " << i << '\n';

  // map, iterator

  map<string, int> m;
  m.insert({"Dog", 36});
  m["Dog"] = 1;
  m["Dog"]++;  // 없는 key를 요구할 시 0 반환

  map<string, int>::iterator iterMap;  // 반복자 포인터처럼 사용
  for (iterMap = m.begin(); iterMap != m.end(); iterMap++)
    cout << iterMap->first << ' ' << iterMap->second;
  cout << '\n';

  for (auto iter = m.begin(); iter != m.end(); iter++)  // 간략화
    cout << iter->first << ' ' << iter->second;
  cout << '\n';

  m.erase("Dog");
  m.erase(m.begin(), m.end());
  m.clear();
  m.size();
  m.empty();

  // set

  set<int> setI;
  setI.insert(1);
  setI.insert(2);
  setI.insert(3);

  set<int>::iterator iterSetI;
  iterSetI = setI.find(3);

  cout << "iterSetI: " << *iterSetI << '\n';

  // keyboard shortcuts: alt + drag, f11, f10

  return 0;
}

int pow(int a, int n) {
  if (!n) return 1;
  int ret = pow(a, n / 2);
  ret *= ret;
  if (n % 2) ret *= a;  // n이 홀수
  return ret;
}
