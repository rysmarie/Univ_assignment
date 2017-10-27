#include <stdio.h>

int strcmp1(char *s, char*t){
  int i;
  for(i=0; s[i]==t[i]; i++){
    if(s[i]=='\0') return 0;
  }
  return s[i] - t[i];
}

int main(){
  char *str1 = "abcde", *str2 = "abdce";
  printf("strcmp1(\"abcde\", \"abdce\") = %d\n", strcmp1(str1, str2));
  return 0;
}
