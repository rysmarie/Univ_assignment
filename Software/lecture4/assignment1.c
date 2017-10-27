#include <stdio.h>
#include <stdlib.h>

int main() {
  int *i, *sum;
  i = (int *)malloc(sizeof(int));
  sum = (int *)malloc(sizeof(int));
  *sum = 0;
  for ((*i) = 0; *i <= 10; (*i)++) {
    (*sum) = (*sum) + (*i);
  }
  printf("*sum = %d\n", *sum);
  return 0;
}
