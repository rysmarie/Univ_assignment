#include <stdio.h>

int strlen1(char *s) {
  int cnt = 0;
  while (*(s++) != '\0') {
    cnt++;
  }
  return cnt;
}

int main() {
  char *str = "hello, world!";
  printf("the length of \"%s\" is %d.\n", str, strlen1(str));
  return 0;
}
