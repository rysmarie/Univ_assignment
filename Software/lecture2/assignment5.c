#include <stdio.h>
#include <string.h>  //strlen()に使う．
int check_kaibun(char str[]);

int main(void) {
  char str[] = "kayak";
  if (check_kaibun(str)) {
    printf("%s is palindrome.\n", str);
  } else {
    printf("%s is NOT palindrome.\n", str);
  }
  return 0;
}

int check_kaibun(char str[]) {
  char *head = str;
  char *tail = &str[strlen(str)-1];
  for(int i=0; i<strlen(str)/2; i++){
    if(*(head++) != *(tail--)){
      return 0;
    }
  }
  return 1;
}
