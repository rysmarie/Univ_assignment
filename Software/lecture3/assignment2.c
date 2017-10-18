#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char i_rsp[3][10] = {"グー", "チョキ", "パー"};

int rsp(int player, int strength) {
  int r = rand() % 100 + 1;
  if (r <= strength) {
    return (player + 1) % 3;
  } else if (r <= (int)(50 + 0.5 * strength)) {
    return player;
  } else {
    return (player + 2) % 3;
  }
}

int main() {
  int strength, opponent, player;
  char player_input;
  printf("強さを設定してね(弱い0<----->強い100):");
  scanf("%d", &strength);
  strength = 100 - strength;
  srand(time(NULL));
  while (1) {
    printf("どれを出す?\ng. グー c. チョキ p. パー q. 終了:");
    scanf(" %c", &player_input);
    printf("%c", player_input);
    if (player_input < 'a') {
      player_input += 'a' - 'A';
    }
    if (player_input == 'q') {
      printf("終了\n");
      break;
    }
    switch (player_input) {
      case 'g':
        player = 0;
        break;
      case 'c':
        player = 1;
        break;
      case 'p':
        player = 2;
        break;
      default:
        printf("g, c, p, qのどれかを入力してね\n");
        continue;
    }
    opponent = rsp(player, strength);
    printf("相手は%sを出したよ\n", i_rsp[opponent]);
    if (opponent == player) {
      printf("あいこ\n");
    } else if (opponent == (player + 1) % 3) {
      printf("勝ち!\n");
    } else {
      printf("負け\n");
    }
  }

  return 0;
}
