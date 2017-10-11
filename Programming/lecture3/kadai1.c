#include <stdio.h>

#define N_MAX 200
#define INF 1e8
float memo[N_MAX];
double _legendre(int n, double x) {
  if (memo[n] != INF) {
    return memo[n];
  }
  memo[n] =
      ((2 * n - 1) * x * _legendre(n - 1, x) - (n - 1) * _legendre(n - 2, x)) /
      n;
  return memo[n];
}

double legendre(int n, double x) {
  for (int i = 0; i < N_MAX; i++) {
    memo[i] = INF;
  }
  memo[0] = 1;
  memo[1] = x;
  return _legendre(n, x);
}

int main() {
  printf("P16(0.5) = %f\nP32(0.7) = %f\n", legendre(16, 0.5),
         legendre(32, 0.7));
  printf("P128(0.5) = %f\n", legendre(128, 0.5));
  return 0;
}
