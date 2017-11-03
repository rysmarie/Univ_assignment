#include <stdio.h>
#include <string.h>

const char roman[] = "MDCLXVI";

int r2num(char r) {
  switch (r) {
    case 'M':
      return 1000;
      break;
    case 'D':
      return 500;
      break;
    case 'C':
      return 100;
      break;
    case 'L':
      return 50;
      break;
    case 'X':
      return 10;
      break;
    case 'V':
      return 5;
      break;
    case 'I':
      return 1;
      break;
  }
  return -1;
}

int sign(char r1, char r2) {
  if (r1 == r2) return 0;
  for (int i = 0; i < strlen(roman); i++) {
    if (r1 == roman[i]) {
      return 1;
    } else if (r2 == roman[i]) {
      return -1;
    }
  }
  return -2;
}

int roman2num(char *s) {
  int sum = 0, temp = 0;
  temp = r2num(*s);
  while (*(++s) != '\0') {
    if (*s == *(s - 1)) {
      temp += r2num(*s);
      continue;
    }
    sum += sign(*(s - 1), *s) * temp;
    temp = r2num(*s);
  }
  return sum + temp;
}

int main(){
  printf("XIV = %d\n", roman2num("XIV"));
  printf("CDXCV = %d\n", roman2num("CDXCV"));
  printf("MCMXLV = %d\n", roman2num("MCMXLV"));
  printf("MMMCMXCIX = %d\n", roman2num("MMMCMXCIX"));
  return 0;
}
