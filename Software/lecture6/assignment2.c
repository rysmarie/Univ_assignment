#include <stdio.h>
#include <stdlib.h>
#define MAXCT 30000

double random_float(double, double);

int main() {
  int seed;
  int k, ct = 0;
  float x, y;

  scanf("%d", &seed);
  printf("seed = %d\n", seed);
  srand(seed);

  for (int i = 0; i < MAXCT; i++) {
    x = random_float(0, 1);
    y = random_float(0, 1);
    if (x * x + y * y <= 1) {
      ct++;
    }
  }

  printf("Approx. PI = %f\n", 4.0 * ct / MAXCT);
}

double random_float(double min, double max) {
  return min + ((max - min) * rand()) / RAND_MAX;
}
