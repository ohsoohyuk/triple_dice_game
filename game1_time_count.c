#include <stdio.h>
#include <time.h>
#include "game1_main.h"
#include "game1_dice_rolling.h"
#include "game1_time_count.h"

void time_count(int** board, int playernumber) {
	//나온 방향으로 주사위를 움직이게 만듦
	dice_rolling(board);

	clock_t start = clock();

	inputEnswer(playernumber);

	clock_t end = clock();

	play.duration[playernumber] = (float)(end - start) / CLOCKS_PER_SEC;
}

void inputEnswer(int playernumber) {
	printf("\n\nplayer%d님 1번면부터 6번면까지 차례대로 입력하시오.\n", playernumber);

	printf("1번(윗면) 2번(뒷면) 3번(오른쪽면) 4번(왼쪽면) 5번(앞면) 6번(밑면) : ");

	for (int i = 0; i < 6; i++) {
		int input = 0;

		scanf_s("%d", &input);

		if (input == dice.dice_array[i]) {
			play.result++;
		}
	}
}