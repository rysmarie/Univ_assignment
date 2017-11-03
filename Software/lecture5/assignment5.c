#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#define N_ROWS 10
#define N_COLS 10
#define LIVING '#'
#define DEAD '.'
void print_screen(char matrix[N_ROWS][N_COLS + 1]) {
  for (int i = 0; i < N_ROWS; i++) {
    for (int j = 0; j < N_COLS; j++) {
      if (matrix[i][j] == LIVING) {
        printf("\033[41m　");
      } else {
        printf("\033[47m　");
      }
    }
    printf("\033[49m\n");
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

void cycle(char matrix[][N_COLS + 1]) {
  char neighbor[8][2] = {{1, 0},  {1, 1},   {0, 1},  {-1, 1},
                         {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
  int i, j, n, livingcells, di, dj;
  for (i = 0; i < N_ROWS; i++) {
    for (j = 0; j < N_COLS; j++) {
      livingcells = 0;
      for (n = 0; n < 8; n++) {
        di = neighbor[n][0];
        dj = neighbor[n][1];
        if (i + di < N_ROWS && i + di > 0 && j + dj < N_COLS && j + dj > 0) {
          if (matrix[i + di][j + dj] == LIVING) livingcells++;
        }
      }
      if (matrix[i][j] == LIVING && !(livingcells == 2 || livingcells == 3)) {
        matrix[i][j] = DEAD;
      } else if (matrix[i][j] == DEAD && livingcells == 3) {
        matrix[i][j] = LIVING;
      }
    }
  }
}
int main() {
  char matrix[N_ROWS][N_COLS + 1], fname[256], readline[N_COLS], c;
  int x, y, i, cursor_x = 0, cursor_y = 0;
  FILE *fi, *fo;
  struct termios save_settings;
  struct termios settings;

  atexit(exit_screen);

  printf(
      "wasdで移動し, スペースキーで生きたセルを作成できます. "
      "nで終了できます.\n");
  printf(
      "初期配置を保存しているファイル名を入力してください. (なければnoと入力): "
      "\n");
  scanf("%s", fname);
  fi = fopen(fname, "r");
  if (fi == NULL) {
    init_screen(matrix, DEAD);
  } else {
    i = 0;
    while (fgets(matrix[i++], N_COLS + 1, fi) != NULL)
      ;
    fclose(fi);
  }
  tcgetattr(fileno(stdin), &save_settings);
  settings = save_settings;

  settings.c_lflag &= ~(ECHO | ICANON); /* echobackしない & LFを待たない */
  tcsetattr(fileno(stdin), TCSANOW, &settings);
  fcntl(fileno(stdin), F_SETFL, O_NONBLOCK); /* non blocking */
  while (1) {
    c = getchar();
    if (c == 'n') break;
    if (c == 'w') cursor_y--;
    if (c == 's') cursor_y++;
    if (c == 'd') cursor_x++;
    if (c == 'a') cursor_x--;
    if (c == ' ') {
      matrix[cursor_y][cursor_x] = LIVING;
    }
    if (cursor_x < 0) cursor_x = 0;
    if (cursor_y < 0) cursor_y = 0;
    if (cursor_x >= N_COLS) cursor_x = N_COLS - 1;
    if (cursor_y >= N_ROWS) cursor_y = N_ROWS - 1;
    system("clear");
    printf("\033[0;0H");
    print_screen(matrix);
    printf("\033[%d;%dH__\033[1D", cursor_y + 1, cursor_x * 2 + 1);
    cycle(matrix);
    fflush(stdout);
    sleep(1);
  }
  return 0;
}
