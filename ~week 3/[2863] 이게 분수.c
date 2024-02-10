#include <stdio.h>

int main() {
  double A, B, C, D;
  double max = 0;
  int trial;
  scanf("%lf %lf %lf %lf", &A, &B, &C, &D);

  for (int i = 0; i < 4; i++) {
    double temp = A / C + B / D;
    if (max < temp) {
      max = temp;
      trial = i;
    }
    double temp_A = A;
    A = C;
    C = D;
    D = B;
    B = temp_A;
  }

  printf("%d\n", trial);

  return 0;
}