#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define N_ROWS 10
#define N_COLS 10
void print_screen(char matrix[N_ROWS][N_COLS + 1]) {
  for (int i = 0; i < N_ROWS; i++) {
    printf("%s\n", matrix[i]);
  }
}

void init_screen(char matrix[][N_COLS + 1], char symbol) {
  for (int i = 0; i < N_ROWS; i++) {
    for (int j = 0; j < N_COLS; j++) {
      matrix[i][j] = symbol;
    }
    matrix[i][N_COLS] = '\0';
  }
}

void exit_screen() {
  system("clear");
  printf("\033[0;0H");
}

void save_screen(char *fname, char matrix[N_ROWS][N_COLS + 1]) {
  FILE *fo;
  fo = fopen(fname, "w");
  for (int i = 0; i < N_ROWS; i++) {
    fprintf(fo, "%s", matrix[i]);
  }
  fclose(fo);
}
int main() {
  char matrix[N_ROWS][N_COLS + 1], fname[256], readline[N_COLS], c;
  int x, y, i;
  FILE *fi, *fo;
  atexit(exit_screen);

  printf("Input filename. (or \"no\" to init matrix with \" - \")\n");
  scanf("%s", fname);
  fi = fopen(fname, "r");
  if (fi == NULL) {
    init_screen(matrix, '-');
  } else {
    i = 0;
    while (fgets(matrix[i++], N_COLS + 1, fi) != NULL)
      ;
    fclose(fi);
  }
  while (1) {
    print_screen(matrix);
    printf("input: x y c\n");
    scanf("%d %d %c", &x, &y, &c);
    matrix[y][x] = c;
    save_screen("data.txt", matrix);
  }
  return 0;
}
