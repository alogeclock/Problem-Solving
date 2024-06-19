#include <stdio.h>

int main() {
  int age, weight;
  while (1) {
    char name[20];
    scanf(" %s %d %d", name, &age, &weight);
    if (age == 0) break;
    if (age > 17 || weight >= 80)
      printf("%s Senior\n", name);
    else
      printf("%s Junior\n", name);
  }
  return 0;
}