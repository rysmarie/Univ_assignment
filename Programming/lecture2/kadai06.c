#include <stdio.h>
#include <stdbool.h>

int gcd(int a, int b) {
  int q = a / b;
  int r = a % b;

  if (r == 0) {
    return b;
  }
  return gcd(b, r);
}

bool isPythagoras(int x, int y, int z) { return (x * x + y * y == z * z); }
int main() {
  int x, y, z, z2, r1, r2;
  for (x = 1; x < 1000; x++) {
    for (y = x; y < 1000; y++) {
      for (z = 0; z < 1000; z++) {
        if (isPythagoras(x, y, z)) {
          r1 = gcd(x, y);
          r2 = gcd(z, r1);
          if (r2 == 1) {
            printf("%d^2 + %d^2 = %d^2\n", x, y, z);
          }
        }
      }
    }
  }
  return 0;
}
