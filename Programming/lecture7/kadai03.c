#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG printf("HERE\n");
#define INF 1e8
typedef struct _namelist {
  char name[255];
  int age;
  double height, weight;
  struct _namelist *prev;
  struct _namelist *next;
} namelist;

void release_list(namelist *p) {
  if (p->next == NULL) {
    free(p);
  }
  release_list(p->next);
}

void delete(namelist *root, char *name){
  for(namelist *nl=root; nl!=NULL; nl = nl->next){
    if(strcmp(nl->name, name)==0){
      nl->prev->next = nl->next;
      nl->next->prev = nl->prev;
      free(nl);
    }
  }
  printf("name:%s not found.\n", name);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("コマンドライン引数を指定してください.\n");
    return 1;
  }
  FILE *fi;
  char name[255], del_name[255];
  int age;
  double height, weight;
  namelist *root, *nl, *last;


  if ((fi = fopen(argv[1], "r")) == NULL) {
    printf("ファイル名%sが開けませんでした.\n", argv[1]);
    return 1;
  }

  while (fscanf(fi, "%[^,],%d,%lf,%lf\n", name, &age, &height, &weight) !=
         EOF) {
    nl = (namelist *)malloc(sizeof(namelist));
    strcpy(nl->name, name);
    nl->age = age;
    nl->height = height;
    nl->weight = weight;
    if (root == NULL) {
      root = nl;
    } else {
      nl->prev = last;
      last->next = nl;
    }
    last = nl;
  }
  fclose(fi);
  for (nl = root; nl != NULL; nl = nl->next) {
    printf("name:%s\n\tage:%d\n\theight:%f\n\tweight:%f\n", nl->name, nl->age, 
           nl->height, nl->weight);
  }
  printf("name?\n");
  scanf("%s", del_name);
  delete(root, del_name);
  for (nl = root; nl != NULL; nl = nl->next) {
    printf("name:%s\n\tage:%d\n\theight:%f\n\tweight:%f\n", nl->name, nl->age, 
           nl->height, nl->weight);
  }
  release_list(root);

  return 0;
}
