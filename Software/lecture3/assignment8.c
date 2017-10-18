#include <stdbool.h>
#include <stdio.h>
#define NALPHA 26

int main() {
  int count[NALPHA][NALPHA];
  int c, i, j, min_index, max_index;
  int last_alpha = -1, sums[NALPHA];
  double prob_table[NALPHA][NALPHA];
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
    min_index = 0;
    max_index = 0;
    for (j = 1; j < NALPHA; j++) {
      if (prob_table[i][j] != 0 &&
          (prob_table[i][j] < prob_table[i][min_index] ||
           prob_table[i][min_index] == 0.0)) {
        min_index = j;
      }
      if (prob_table[i][j] > prob_table[i][max_index]) {
        max_index = j;
      }
    }
    printf("%c: min -> %c (%e), max -> %c (%e)\n", 'a' + i, 'a' + min_index,
           prob_table[i][min_index], 'a' + max_index, prob_table[i][max_index]);
  }

  return 0;
}
