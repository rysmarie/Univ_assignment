#include <stdio.h>

int main(){
  int n = 158340421;
  int i;
  double epsilon = 1e-8, x=10, lastx=1;

  #define fabs(a) ((a)>0 ? (a):-1*(a))
  for(i=0; i<1e4; i++){
    lastx = x;
    x = -(1/(3*x*x)) * (x*x*x-n) + x;
    if(fabs(x-lastx)<epsilon){
      break;
    }
  }
  printf("%f", x);
  return 0;
}
