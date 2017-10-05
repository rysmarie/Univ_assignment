#include <stdio.h>


int gcd(int a, int b){
  int q = a/b;
  int r = a%b;

  if(r == 0){
    return b;
  }
  return gcd(b, r);
}

int main(){
  int r;
  int a = 8733;
  int b = 64681;
  r = gcd(a, b);
  printf("gcd(%d, %d) = %d\n", a, b, r);
  return 0;
}
