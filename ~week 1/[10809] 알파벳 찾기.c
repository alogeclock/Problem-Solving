#include <stdio.h>

int main() {
  int alphabet[26];
  char word[100];

  scanf("%s", word);

  for (int i = 0; i < 26; i++)
    alphabet[i] = -1;

  for (int i = 0; word[i]; i++) {
    if (alphabet[(int)word[i] - 97] == -1) alphabet[(int)word[i] - 97] = i;
  }

  for (int i = 0; i < 26; i++)
    printf("%d ", alphabet[i]);

  return 0;
}