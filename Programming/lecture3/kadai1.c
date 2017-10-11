#include <stdio.h>

#define N_MAX 200
#define INF 1e8
float dp[N_MAX];
double _legendre(int n, double x) {
  if (dp[n] != INF) {
    return dp[n];
  }
  dp[n] =
      ((2 * n - 1) * x * _legendre(n - 1, x) - (n - 1) * _legendre(n - 2, x)) /
      n;
  return dp[n];
}

double legendre(int n, double x) {
  for (int i = 0; i < N_MAX; i++) {
    dp[i] = INF;
  }
  dp[0] = 1;
  dp[1] = x;
  return _legendre(n, x);
}

int main() {
  printf("P16(0.5) = %f\nP32(0.7) = %f\n", legendre(16, 0.5),
         legendre(32, 0.7));
  printf("P128(0.5) = %f\n", legendre(128, 0.5));
  return 0;
}
