#include <stdio.h>
void increment(int* a){
  (*a)++;
}
int main() {
  int a = 10;
  increment(&a);
  printf("%d\n", a);
  return 0;
}
