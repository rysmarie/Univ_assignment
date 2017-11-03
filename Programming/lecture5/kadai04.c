#include <stdio.h>

void uppercase(char *s) {
  while (*s != '\0') {
    if (*s >= 'a') *s -= 'a' - 'A';
    s++;
  }
}

int main(){
  char s[] = "AoEui";
  uppercase(s);
  printf("%s\n", s);
  return 0;
}
