#include <stdio.h>
#include <stdlib.h>

struct monomial {
  int c;
  int n;
};

struct monomial *construct_monomial(int c, int n) {
  struct monomial *m;
  m = (struct monomial *)malloc(sizeof(struct monomial));
  m->c = c;
  m->n = n;
  return m;
}
void destruct_monomial(struct monomial *m){
  free(m);
}
void diff_monomial(struct monomial *m) {
  m->c *= m->n;
  m->n -= 1;
}
void print_monomial(struct monomial *m) { 
  printf("%d*x^%d\n", m->c, m->n);
}

int main() {
  struct monomial *m1;
  m1 = construct_monomial(-4, 10);
  print_monomial(m1);
  diff_monomial(m1);
  print_monomial(m1);
  destruct_monomial(m1);
  return 0;
}
