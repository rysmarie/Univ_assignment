#include <stdio.h>

int main(){
  int n = 158340421;
  int i = 1;
  int pow3;

  while((pow3 = i*i*i) <= n){
    if(pow3 == n){
      printf("%d\n", i);
      break;
    }
    i++;
  }
  return 0;
}
