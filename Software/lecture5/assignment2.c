#include <stdio.h>
#include <stdlib.h>
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

int main() {
  char matrix[N_ROWS][N_COLS + 1], c;
  int x, y;
  atexit(exit_screen);
  init_screen(matrix, '-');
  while (1) {
    print_screen(matrix);
    printf("input: x y c\n");
    scanf("%d %d %c", &x, &y, &c);
    matrix[y][x] = c;
  }
  return 0;
}
