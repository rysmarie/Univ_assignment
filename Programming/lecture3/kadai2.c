#include <stdio.h>

double _sqrt2(int n, double z) {
  if (n >= 100) {
    return z;
  }
  return 1 + (z-1) / (1 + _sqrt2(n + 1, z));
}

double sqrt2(double z) { return _sqrt2(0, z); }

int main() {
  printf("sqrt(10) = %f\n", sqrt2(10));
  return 0;
}
