#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define N 1000

bool prime_table[N + 1];

void gen_prime_table() {
  // init table
  for (int i = 0; i < (N + 1); i++) {
    prime_table[i] = true;
  }
  prime_table[1] = false;
  for (int i = 2; i < sqrt(N); i++) {
    if (prime_table[i]) {
      for (int j = 2; j <= (int)(N / i); j++) {
        prime_table[i * j] = false;
      }
    }
  }
}

int main() {
  bool goldbach = true, flag;
  gen_prime_table();

  for(int n=4;n<=1000;n+=2){
    flag = false;
    for(int i=2;i <= n;i++){
      if(prime_table[i]){
        if(prime_table[n-i]){
          printf("%d = %d + %d\n", n, i, n-i);
          flag = true;
          break;
        }
      }
    }
    if(!flag){
      goldbach = false;
      printf("Goldbach's conjecture is false.\n");
      break;
    }
  }
  if(goldbach){
    printf("Goldbach's conjecture is true (from 4 to 1000).\n");
  }
  return 0;
}
