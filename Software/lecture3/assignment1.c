#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char str[5] = {'\0'};
  for (int i = 1; i <= 1000; i++) {
    printf("%d", i);
    if (i % 3 == 0) {
      printf("!!!");
    } else {
      sprintf(str, "%d", i);
      for (int j = 0; j < strlen(str); j++) {
        if (str[j] == '3') {
          printf("!!!");
          break;
        }
      }
    }
    printf("\n");
  }
  return 0;
}
