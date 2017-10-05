#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define N 1000

bool prime_table[N + 1];

int main(){
  //init table
  for(int i=0;i<(N+1);i++){
    prime_table[i] = true;
  }
  prime_table[1] = false;
  for(int i=2;i<sqrt(N);i++){
    if(prime_table[i]){
      for(int j=2;j<=(int)(N/i);j++){
        prime_table[i*j] = false;
      }
    }
  }
  for(int i=2;i<N+1;i++){
    if(prime_table[i]){
        printf("%d\n", i);
    }
  }
  return 0;
}
