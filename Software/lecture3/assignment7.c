#include <stdbool.h>
#include <stdio.h>
#define NALPHA 26

int main() {
  int count[NALPHA][NALPHA];
  int c, i, j;
  int last_alpha = -1;
  for (i = 0; i < NALPHA; ++i) {
    for (j = 0; j < NALPHA; j++) {
      count[i][j] = 0;
    }
  }

  while ((c = getchar()) != EOF) {
    if (c >= 'a' && c <= 'z') {
      if (last_alpha != -1) {
        count[last_alpha][c - 'a']++;
      }
      last_alpha = c -'a';
    }else{
      last_alpha = -1;
    }
  }

  for (i = 0; i < NALPHA; i++) {
    for (j=0; j<NALPHA; j++){
    printf("%c%c : %d\n", 'a' + i, 'a' + j, count[i][j]);
    }
  }

  return 0;
}
