#pragma once
typedef struct {
	int N, M, x, y, K;
	int score[10];
	double duration[10];
	int result;
}number;

typedef struct {
	int dice_array[6];
	int way;
}rolling;

number play;
rolling dice;

void game1();
void maingame1_rule();
void maingame1_start();
void maingame1_end();
int** createValue();
void time_count(int** board, int playernumber);