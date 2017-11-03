#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG printf("HERE\n");

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("コマンドライン引数を指定してください\n");
    return 1;
  }
  FILE *fi;
  if ((fi = fopen(argv[1], "r")) == NULL) {
    printf("ファイル名%sが開けませんでした\n", argv[1]);
    return 1;
  }

  char c, *tok, line[1024];
  int row = 0, column = 1, *matrix, i, j;
  while ((c = getc(fi)) != EOF) {
    if (row == 0 && c == '\t') column++;
    if (c == '\n') row++;
  }
  fseek(fi, 0L, SEEK_SET);
  matrix = (int *)malloc(sizeof(int) * row * column);
  for(i=0; i<row; i++){
    fgets(line, 1024, fi);
    tok = strtok(line, "\t");
    for(j=0; j<column; j++){
      matrix[i*column+j] = atoi(tok);
      tok = strtok(NULL, "\t");
    }
  }

  for(i=0; i<row; i++){
    for(j=0; j<column; j++){
      printf("%d\t", matrix[i*column+j]);
    }
    printf("\n");
  }
  free(matrix);
  return 0;
}
