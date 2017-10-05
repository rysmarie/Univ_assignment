#include <math.h>
#include <stdio.h>

int main() {
  double last_sum;
  double sum = pow(log(2), 2);
  int n = 1;
  while (1) {
    last_sum = sum;
    sum += 1.0/(pow(n, 2) * pow(2, n-1));
    if(fabs(last_sum - sum) < 1e-8){
      break;
    }
    n += 1;
  }
  printf("pi ~ %f", sqrt(6*sum));
  return 0;
}
