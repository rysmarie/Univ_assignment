#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define NALPHA 26

int main() {
  int count[NALPHA][NALPHA];
  int c, i, j, min_index, max_index;
  int last_alpha = -1, sums[NALPHA];
  double prob_table[NALPHA][NALPHA], entropy, p;
  for (i = 0; i < NALPHA; ++i) {
    sums[i] = 0;
    for (j = 0; j < NALPHA; j++) {
      count[i][j] = 0;
      prob_table[i][j] = 0.0;
    }
  }

  while ((c = getchar()) != EOF) {
    if (c >= 'a' && c <= 'z') {
      if (last_alpha != -1) {
        count[last_alpha][c - 'a']++;
        sums[last_alpha]++;
      }
      last_alpha = c - 'a';
    } else {
      last_alpha = -1;
    }
  }
  for (i = 0; i < NALPHA; i++) {
    for (j = 0; j < NALPHA; j++) {
      prob_table[i][j] = (double)count[i][j] / sums[i];
    }
  }

  for (i = 0; i < NALPHA; i++) {
    entropy = 0.0;
    for (j = 0; j < NALPHA; j++) {
      if (prob_table[i][j] != 0) {
        entropy += -prob_table[i][j] * log10(prob_table[i][j]) / log10(2);
      }
    }
    printf("%c: entropy = %e\n", 'a' + i, entropy);
  }

  return 0;
}
