// idea: stack

/*
1. 스택에는 왼쪽 괄호만 넣고, 최근 괄호는 항상 s.top()이 된다.
2. 어떤 괄호든 닫히면 값이 sum[idx] 배열에 더해져서 관리된다.
3. 바로 이전 괄호가 닫은 괄호라면, 이전 값에 곱한다.
4. 이전 괄호가 연 괄호라면, 이전 값에 더한다.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define PINF 1000000007

ll sum[31]; // n겹의 괄호에 저장된 값의 합

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string s; cin >> s;

  stack<char> st;
  ll ans = 0, level = 0; // level: 겹쳐진 괄호의 개수
  char prev;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(' || s[i] == '[') {
      st.push(s[i]);
      level++;
    }

    else if (s[i] == ')') {
      if (st.empty()) goto ERROR;

      if (st.top() == '(') {
        if (prev == ')' || prev == ']') {
          sum[level - 1] += sum[level] *= 2;
          sum[level] = 0; 
        } else
          sum[level - 1] += 2;
        level--;
        st.pop();
      }
      else goto ERROR;
    }

    else if (s[i] == ']') {
      if (st.empty()) goto ERROR;

      if (st.top() == '[') {
        if (prev == ')' || prev == ']') {
          sum[level - 1] += sum[level] *= 3;
          sum[level] = 0; 
        } else
          sum[level - 1] += 3;
        level--;
        st.pop();
      } else
        goto ERROR;
    }

    prev = s[i];
  }

  if (st.size()) goto ERROR;
  cout << sum[0] << '\n';
  
  return 0;

  ERROR:
  cout << "0\n";
}