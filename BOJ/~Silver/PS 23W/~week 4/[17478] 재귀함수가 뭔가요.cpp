#include <bits/stdc++.h>
using namespace std;

string str_1 = "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
string str_2[4] = {"\"재귀함수가 뭔가요?\"\n",
                   "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 "
                   "통달한 선인이 있었어.\n",
                   "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 "
                   "지혜롭게 대답해 주었지.\n",
                   "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 "
                   "선인에게 한 선비가 찾아와서 물었어.\"\n"};
string str_3[3] = {"\"재귀함수가 뭔가요?\"\n",
                   "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n",
                   "라고 답변하였지.\n"};
int N;

void JH(int k) {
  if (k == N) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < k; j++) cout << "____";
      cout << str_3[i];
    }
    return;
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < k; j++) cout << "____";

    if (i == 4) {
      cout << str_3[2];
      continue;
    }
    cout << str_2[i];
    if (i == 3) JH(k + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  cout << str_1;

  JH(0);

  return 0;
}