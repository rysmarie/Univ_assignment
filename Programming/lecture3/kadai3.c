#include <math.h>
#include <stdio.h>

double neuton(double (*func)(double), double (*deriv)(double), double x, double y) {
  double delta = (func(x) - y) / deriv(x);
  if (fabs(delta) < 1e-8) {
    return x;
  }
  return neuton(func, deriv, x - delta, y);
}

double func(double x){
  return exp(x) + x;
}
double deriv(double x){
  return exp(x) + 1;
}

double func2(double x){
  return pow(x, 5);
}
double deriv2(double x){
  return 5*pow(x, 4);
}
int main(){
  printf("f(x) = exp(x) + x, f(x)=0 -> x~%f\n", neuton(func, deriv, 10, 0));
  printf("g(x) = x^5, g(x)=1 -> x~%f\n", neuton(func2, deriv2, 10, 2));
  return 0;
}
