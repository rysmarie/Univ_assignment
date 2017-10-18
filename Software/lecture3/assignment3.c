#include <stdio.h>
#include <math.h>


int main(){
  double x;
  for(int i=0;i<=1000;i++){
    x = 5.0 - i/100.0;
    printf("%f %f\n", x*M_PI, sin(x*M_PI)/(x*M_PI));
  }
  return 0;
}
