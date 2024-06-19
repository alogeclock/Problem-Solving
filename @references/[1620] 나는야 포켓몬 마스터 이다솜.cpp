// idea: lambda function

#include <algorithm>
#include <iostream>
#include <vector>
#define MAX_NUMBER 100001
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int pokemon, question;

  cin >> pokemon >> question;

  vector<pair<int, string>> pokedex(pokemon);
  vector<pair<int, string>> sorted_pokedex(pokemon);

  for (int i = 0; i < pokemon; i++) {
    cin >> pokedex[i].second;
    pokedex[i].first = i + 1;
    sorted_pokedex[i] = pokedex[i];
  }

  sort(sorted_pokedex.begin(), sorted_pokedex.end(),
       [](const pair<int, string> &a, const pair<int, string> &b) { return a.second < b.second; });
       // 오름차순

  for (int i = 0; i < question; i++) {
    string input;
    cin >> input;

    if (isdigit(input[0])) {
      int idx = stoi(input);
      cout << pokedex[idx - 1].second << "\n";
    } else {
      int left, right, mid;
      left = 0, right = pokemon - 1;

      while (left <= right) {
        mid = (left + right) / 2;
        int cmp = input.compare(sorted_pokedex[mid].second);

        if (cmp == 0) {
          cout << sorted_pokedex[mid].first << "\n";
          break;
        } else if (cmp > 0)
          left = mid + 1;
        else
          right = mid - 1;
      }
    }
  }

  return 0;
}