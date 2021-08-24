#include <stdio.h>
#include "startScreen_main.h"
#include "game1_main.h"
#include "game2_main.h"
#include "game3_main.h"
#include "totalranking.h"
#include "Allcommon.h"
#include "game3_variable.h"

Game3 initScore() {
	for (int i = 0; i < PLAYER; i++) {
		totalscore[i] = 0;
	}

	for (int i = 0; i < 6; i++) {
		dice.dice_array[i] = 0;
	}

	Game3 game3Var = {
		{ 0,0,0,0,0,0,0,0,0,0 },           //주사위의 합산 배열, 마지막에 메인게임2 스코어 정렬
		{ 0,0,0,0,0,0,0,0,0,0 },          //메인게임 플레이어 점수를 나타내는 배열
		{ 3,3,3,3,3,3,3,3,3,3 },          //말이 움직이면 빈칸 채우기 용도
		{ 4,6,8,10,12,4,6,8,10,12 },       //말이 움직이면 빈칸 채우기 용도
		60,
		0
	};

	return game3Var;
}

int main(void) {
	while (1) {
		menuscreen();
		game1();
		minigame();
		game3();
		outputTotalranking();
		game3Var = initScore();
	}

	return 0;
}