#include <bits/stdc++.h>

int main() {
  int numberCards, target;
  int sum = 0;

  scanf("%d %d", &numberCards, &target);
  int* cards = new int[numberCards];
  for (int i = 0; i < numberCards; i++) {
    scanf("%d", &cards[i]);
  }

  for (int i = 0; i < numberCards; i++) {
    for (int j = i + 1; j < numberCards; j++) {
      for (int k = j + 1; k < numberCards; k++) {
        int cardSum = cards[i] + cards[j] + cards[k];
        if (cardSum <= target && cardSum > sum) sum = cardSum;
      }
    }
  }

  printf("%d\n", sum);

  delete[] cards;

  return 0;
}