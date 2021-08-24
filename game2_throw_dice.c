#include <stdio.h>
#include "game2_thorw_dice.h"
#include "game2_main.h"
#include "Allcommon.h"
//#include "bgm.h"

void throw_dice(char* pri, int diceValue, char order[]) {
	printf("%s", pri);
	temp = getchar();
	while (temp = getchar() != '\n' && temp != EOF);

	printf("주사위가 몇이 나오는지 계산중입니다");
	//playingShuffleSound();

	for (int i = 0; i < 3; i++) {
		printf(".");
		Sleep(500);
	}

	if (order == "첫") {
		printf("\n첫 번째 숫자 주사위값 : %d\n\n", threedice.dice1);
	}
	else if (order == "두") {
		printf("\n두 번째 연산기호 주사위값 : %c\n\n", threedice.dice2[threedice.c]);
	}
	else if (order == "세") {
		printf("\n세 번째 숫자 주사위값 : %d\n\n", threedice.dice3);
	}
}