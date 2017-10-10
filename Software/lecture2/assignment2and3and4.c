#include <stdio.h>

int get_max(int numbers[], int N);
double get_average(int numbers[], int N);
double get_variance(int numbers[], int N);

int main() {
  int numbers[] = {1, 3, 5, 7, 9, 8, 6, 4, 2};
  printf("max is %d.\n", get_max(numbers, 9));
  printf("average is %f.\n", get_average(numbers, 9));
  printf("variance is %f.\n", get_variance(numbers, 9));
  return 0;
}

int get_max(int numbers[], int N) {
  int max = 0;
  for (int i = 0; i < N; i++) {
    if (numbers[i] > max) {
      max = numbers[i];
    }
  }
  return max;
}

double get_average(int numbers[], int N) {
  int sum = 0;
  for (int i = 0; i < N; i++) {
    sum += numbers[i];
  }
  return sum / N;
}

double get_variance(int numbers[], int N) {
  double avr = get_average(numbers, N);
  int sum = 0;
  for (int i = 0; i < N; i++) {
    sum += (numbers[i] - avr) * (numbers[i] - avr);
  }
  return sum / N;
}
