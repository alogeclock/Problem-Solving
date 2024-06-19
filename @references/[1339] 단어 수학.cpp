// idea: map의 value 기준 정렬

#include <bits/stdc++.h>
using namespace std;
#define every(x) x.begin(), x.end()

map<char, int> alphabet;

bool compare(pair<char, int> a, pair<char, int> b) {
  return a.second > b.second;  // 부등호를 거꾸로 해서 내림차순 정렬
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {  // 단어 삽입 후 map에 update
    string word;
    cin >> word;

    int exp = 1;
    for (int j = word.length() - 1; j >= 0; j--) {
      alphabet[word[j]] += exp;
      exp *= 10;
    }
  }

  vector<pair<char, int>> sortByValue(every(alphabet));
  sort(every(sortByValue), compare);  // value 기준 내림차순 정렬

  int sum = 0;
  int multiple = 9;
  for (int i = 0; i < sortByValue.size(); i++) {
    sum += multiple * sortByValue[i].second;  // 최댓값 획득
    multiple--;
  }

  cout << sum << endl;

  return 0;
}