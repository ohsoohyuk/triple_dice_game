#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Allcommon.h"
#include "game1_main.h"
#include "game1_dice_rolling.h"

void dice_rolling(int** board) {
	for (int i = 0; i < play.K; i++) {
		dice.way = rand() % 4 + 1;

		printf("%d ", dice.way);

		switch (dice.way) {
		case 4:
			play.y = moveDice(board, play.y, +1, play.N, 5, 1, 0, 4);
			break;

		case 3:
			play.y = moveDice(board, play.y, -1, -1, 5, 4, 0, 1);
			break;

		case 2:
			play.x = moveDice(board, play.x, -1, -1, 5, 2, 0, 3);
			break;

		case 1:
			play.x = moveDice(board, play.x, +1, play.M, 5, 3, 0, 2);
			break;
		}
	}
}

int moveDice(int** board, int locChange, int incORred, int limitArea, int move1, int move2, int move3, int move4) {
	int temdice[6];

	memmove(temdice, dice.dice_array, sizeof(int) * 6);

	if (locChange + incORred != limitArea) {
		dice.dice_array[move2] = temdice[move1];
		dice.dice_array[move3] = temdice[move2];
		dice.dice_array[move4] = temdice[move3];
		dice.dice_array[move1] = temdice[move4];

		locChange += incORred;

		copyDice(board);
	}

	return locChange;
}

void copyDice(int** board) {
	if (board[play.y][play.x] != 0) {
		dice.dice_array[5] = board[play.y][play.x];
		board[play.y][play.x] = 0;
	}
	else if (board[play.y][play.x] == 0) {
		board[play.y][play.x] = dice.dice_array[5];
	}
}