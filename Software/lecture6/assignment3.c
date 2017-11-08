#include <stdio.h>

double pie( double x0, int N );

int main(){
  double x = 0.1;
  for (int i=1; i<=100; i++){
    x = pie(x, 1);
    printf("%d : %lf\n", i, x);
  }

  return 0;
}

double pie( double x0, int N ){
  if (N<=0) return x0;
  if(x0 <= 0.5) return pie(x0*2, N-1);
  return pie(2-x0*2, N-1);
}
