#include <stdio.h>
#include <math.h>
#define NALPHA 26

int main() {
  int count[NALPHA];
  int c, i, total_alph=0;
  double p, entropy = 0.0;
  for (i = 0; i < NALPHA; ++i) {
    count[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c >= 'a' && c <= 'z') {
      count[c - 'a']++;
      total_alph++;
    }
  }

  for (i = 0; i < NALPHA; i++) {
    p = (double)count[i] / total_alph;
    entropy += -p*log10(p)/log10(2);
  }
  printf("entropy = %e\n", entropy);

  return 0;
}
