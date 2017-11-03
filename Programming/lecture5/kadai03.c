#include <stdio.h>

#define swap(a, b) (a) ^= (b) ^= (a) ^= (b)

void reverse(char *s) {
  char *head, *tail;
  head = s;
  tail = s;
  while (*tail != '\0') tail++;
  tail--;

  while (head < tail) {
    swap(*head, *tail);
    head++;
    tail--;
  }
}
int main() {
  char s[] = "hello";
  reverse(s);
  printf("%s\n", s);
  return 0;
}
