#include <stdio.h>
#include <math.h>
#include <string.h>

int zeller(int year, int month, int day) {
  if (month <= 2){
    month += 12;
    year--;
  }
  int h = year / 100;
  int y = year - h * 100;
  int m = month, d = day;
  return (int)(y + floor(y / 4.0) + floor(h / 4.0) - 2 * h +
             floor(13.0 * (m + 1) / 5.0) + d);
}

int main() {
  char* weekdays[7] = {"Saturday",  "Sunday",   "Monday", "Tuesday",
                         "Wednesday", "Thursday", "Friday"};
  int year, month, day, w;
  printf("input year/month/day:");
  scanf("%d/%d/%d", &year, &month, &day);
  w = zeller(year, month, day);
  printf("%s\n", weekdays[w % 7]);
  return 0;
}
