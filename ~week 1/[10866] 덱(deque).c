#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_DEQUE_SIZE 10001

int deque[10001] = {0};
int dfront = 5000, drear = 5000;

void push_front(int val);
void push_back(int val);
void pop_front();
void pop_back();
void size();
void empty();
void front();
void back();

int main() {
  int command_num, num;
  int val;
  char command[20];

  scanf("%d", &command_num);

  while (command_num--) {
    scanf("%s", command);

    if (!strcmp(command, "push_front")) {
      scanf("%d", &val);
      push_front(val);
    } else if (!strcmp(command, "push_back")) {
      scanf("%d", &val);
      push_back(val);
    } else if (!strcmp(command, "pop_front"))
      pop_front();
    else if (!strcmp(command, "pop_back"))
      pop_back();
    else if (!strcmp(command, "size"))
      size();
    else if (!strcmp(command, "empty"))
      empty();
    else if (!strcmp(command, "front"))
      front();
    else if (!strcmp(command, "back"))
      back();
  }

  return 0;
}

void push_front(int val) {
  if (dfront < 0)
    printf("-1\n");
  else {
    if (dfront == drear)
      deque[drear++] = val;
    else
      deque[--dfront] = val;
  }
}

void push_back(int val) {
  if (drear == MAX_DEQUE_SIZE - 1)
    printf("-1\n");
  else {
    deque[drear++] = val;
  }
}

void pop_front() {
  if (drear == dfront)
    printf("-1\n");
  else {
    printf("%d\n", deque[dfront++]);
  }
}

void pop_back() {
  if (drear == dfront)
    printf("-1\n");
  else {
    printf("%d\n", deque[--drear]);
  }
}

void size() {
  printf("%d\n", drear - dfront);
}

void empty() {
  if (drear - dfront <= 0)
    printf("1\n");
  else
    printf("0\n");
}

void front() {
  if (drear - dfront <= 0)
    printf("-1\n");
  else
    printf("%d\n", deque[dfront]);
}

void back() {
  if (drear - dfront <= 0)
    printf("-1\n");
  else
    printf("%d\n", deque[drear - 1]);
}
