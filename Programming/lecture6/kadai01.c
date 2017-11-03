#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("HERE\n");
#define INF 1e8
typedef struct _namelist {
  char *name;
  int age;
  double height, weight;
  struct _namelist *next;
} namelist;

void release_list(namelist *p) {
  if (p->next == NULL) {
    free(p);
  }
  release_list(p->next);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("コマンドライン引数を指定してください.\n");
    return 1;
  }
  FILE *fi;
  char name[255];
  int age, n, age_min = INF, age_max = -1;
  double height, weight, height_min = INF, height_max = -1, weight_min = INF,
                         weight_max = -1, age_mean, height_mean, weight_mean,
                         age_std, height_std, weight_std;
  namelist *root, *sentinel, *nl, *last;

  sentinel = (namelist *)malloc(sizeof(namelist));

  if ((fi = fopen(argv[1], "r")) == NULL) {
    printf("ファイル名%sが開けませんでした.\n", argv[1]);
    return 1;
  }
  while (fscanf(fi, "%[^,],%d,%lf,%lf\n", name, &age, &height, &weight) !=
         EOF) {
    n++;
    age_mean += age;
    height_mean += height;
    weight_mean += weight;
    if (age < age_min) age_min = age;
    if (age > age_max) age_max = age;
    if (height < height_min) height_min = height;
    if (height < height_min) height_min = height;
    if (weight > weight_max) weight_max = weight;
    if (weight > weight_max) weight_max = weight;

    nl = (namelist *)malloc(sizeof(namelist));
    nl->name = name;
    nl->age = age;
    nl->height = height;
    nl->weight = weight;
    nl->next = sentinel;
    if (root == NULL) {
      root = nl;
    } else {
      last->next = nl;
    }
    last = nl;
  }
  fclose(fi);
  age_mean /= n;
  height_mean /= n;
  weight_mean /= n;
  for (nl = root; nl != sentinel; nl = nl->next) {
    age_std += (nl->age - age_mean) * (nl->age - age_mean);
    height_std += (nl->height - height_mean) * (nl->height - height_mean);
    weight_std += (nl->weight - weight_mean) * (nl->weight - weight_mean);
  }
  age_std = sqrt(age_std / n);
  height_std = sqrt(height_std / n);
  weight_std = sqrt(weight_std / n);
  printf("Age: (max, min, mean, stdev) = (%d, %d, %lf, %lf)\n", age_max,
         age_min, age_mean, age_std);
  printf("Height: (max, min, mean, stdev) = (%lf, %lf, %lf, %lf)\n", height_max,
         height_min, height_mean, height_std);
  printf("Weight: (max, min, mean, stdev) = (%lf, %lf, %lf, %lf)\n", weight_max,
         weight_min, weight_mean, weight_std);
  release_list(root);

  return 0;
}
