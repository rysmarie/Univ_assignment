#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isPythagoras(int x, int y, int z){
  return (x*x + y*y == z*z);
}
int main(){
  int x, y, z, z2;
  for(x=1; x<1000; x++){
    for(y=x; y<1000; y++){
      for(z=0; z<1000; z++){
        if(isPythagoras(x, y, z)){
          printf("%d^2 + %d^2 = %d^2\n", x, y, z);
        }
      }
    }
  }
  return 0;
}
