#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("コマンドライン引数を2つ指定してください\n");
    return 1;
  }
  FILE *fi, *fo;
  if ((fi = fopen(argv[1], "r")) == NULL) {
    printf("ファイル名%sが開けませんでした\n", argv[1]);
    return 1;
  }
  fo = fopen(argv[2], "w");
  char c[] = "  .";
  char flag = 1;
  const char doc_head = 1, after_dot = 2, after_quot;

  while ((c[0] = getc(fi)) != EOF) {
    if (c[0] >= 'a' && c[0] <= 'z') {
      if ((c[1] == ' ' && c[2] == '.') || (c[1] == '"' && c[2] == ' ')) {
        c[0] -= 'a' - 'A';
      }
    }
    if (c[2] == ' ' && c[1] == 'i' &&
        ((c[0] > 'Z' && c[0] < 'a') || c[0] < 'A' || c[0] > 'z')) {
      c[1] -= 'a' - 'A';
    }
    putc(c[1], fo);
    c[2] = c[1];
    c[1] = c[0];
  }
  putc(c[1], fo);

  return 0;
}
