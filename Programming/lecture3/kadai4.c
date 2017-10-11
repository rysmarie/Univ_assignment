#include <stdio.h>

int mod2(int a, int p, int m) {
  if (p == 0) {
    return 1;
  }
  return a * mod2(a, p - 1, m) % m;
}

int main() {
  printf("541^(1234) mod 1299709 = %d", mod2(541, 1234, 1299709));
  return 0;
}
