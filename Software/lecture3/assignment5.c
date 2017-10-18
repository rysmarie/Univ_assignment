#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define K 5  // スロットマシンの数
#define N 1e6  // コインの数．採点時には1,000,000などの大きな数にする．

int bet(int k);  //変更不可
int argmax(double *);

int main() {  //自由に変更して良い
  srand((unsigned)time(NULL));
  int credit = N, reward = 0, sum = 0;
  int count[K], i, k;
  double reward_table[K], table[K];
  for (i = 0; i < K; i++) {
    count[i] = 0;
    reward_table[i] = 0.0;
  }

  while (credit-- > 0) {
    k = -1;
    for (i = 0; i < K; i++) {
      if (count[i] == 0) {
        k = i;
        break;
      }
      table[i] = reward_table[i] / (count[i] + 1e-8) +
                 1 * (sqrt(2 * log(N - credit) / (count[i] + 1e-8)));
    }
    if (k == -1) {
      k = argmax(table);
    }
    reward = bet(k);
    sum += reward;
    reward_table[k] += reward;
    count[k]++;
  }
  printf("sum = %f\n", (double)sum / N);

  return 0;
}

int argmax(double *all) {
  double max = all[0];
  int am = 0;
  for (int i = 0; i < K; i++) {
    if (all[i] > max) {
      max = all[i];
      am = i;
    }
  }
  return am;
}

// 以下の関数は変更不可
int bet(int k) {  // 入力：スロットマシンの番号　出力：当選金
  // これは例であり，採点時には当選金と確率が変化する
  switch (k) {
    case 0:
      if (rand() % 2 == 0) {  // 2/2
        return 2;
      } else {
        return 0;
      }
      break;
    case 1:
      if (rand() % 7 == 0) {  // 5/7
        return 5;
      } else {
        return 0;
      }
      break;
    case 2:
      if (rand() % 8 == 0) {  // 10/8
        return 10;
      } else {
        return 0;
      }
      break;
    case 3:
      if (rand() % 40 == 0) {  // 50/40
        return 50;
      } else {
        return 0;
      }
      break;
    case 4:
      if (rand() % 200 == 0) {  // 100/200
        return 100;
      } else {
        return 0;
      }
      break;
    default:
      return 0;
  }
}
