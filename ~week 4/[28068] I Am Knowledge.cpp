#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM 100001
#define pii vector<pair<int, int>>

long long joy = 0;
pii funBooks;    // 잃는 즐거움 < 얻는 즐거움인 책들
pii boringBooks; // 얻는 즐거움 < 잃는 즐거움인 책들
bool flag;

// 잃는 즐거움 기준 내림차순 정렬
bool compareBoring(pair<int, int> a, pair<int, int> b) {
  return a.second > b.second;
}

// 잃는 즐거움 기준 오름차순 정렬
bool compareFun(pair<int, int> a, pair<int, int> b) {
  return a.first < b.first;
}

void read(int loss, int get) {
  joy -= loss;

  if (joy < 0)
    flag = 1;

  joy += get;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    if (b - a > 0)
      funBooks.push_back({a, b});
    else
      boringBooks.push_back({a, b});
  }

  sort(funBooks.begin(), funBooks.end(), compareFun);
  sort(boringBooks.begin(), boringBooks.end(), compareBoring);

  for (int i = 0; i < funBooks.size(); i++) {
    read(funBooks[i].first, funBooks[i].second);
  }

  for (int i = 0; i < boringBooks.size(); i++) {
    read(boringBooks[i].first, boringBooks[i].second);
  }

  if (!flag)
    cout << "1\n";
  else
    cout << "0\n";

  // 얻는 즐거움 - 잃는 즐거움이 작은 순서대로 정렬

  return 0;
}