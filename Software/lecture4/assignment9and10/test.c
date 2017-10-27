#include <stdio.h>

int main(){
  int *a, b;
  printf("%lu, %lu\n", sizeof(a), sizeof(b));
  int *c[30], d[30];
  printf("%lu, %lu\n", sizeof(c), sizeof(d));
}
