#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//教科書の通りにしても自分の環境では正しく動きませんでした.
void strcpy1(char *s, char *t) {
  while((*s++ = *t++) != '\0');
}
int main() {
  char *src = "text1";
  char dest[5];
  strcpy1(dest, src);
  printf("src = %s, dest = %s\n", src, dest);
  return 0;
}
