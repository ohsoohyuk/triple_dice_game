#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "Allcommon.h"
#include "game2_thorw_dice.h"
#include "game2_main.h"
#include "fileio.h"
//#include "bgm.h"

game2 threedice = {
	0,0,0,
	{'+','-','*','/'},
	{0,}
};

void minigame_rule() {
	outputTotal("minigame_rule.txt");
}

void minigame() {
	//minigame_Bgm();

	minigameStart();
	minigameEnd();

	//mciSendCommand(miniBgm.wDeviceID, MCI_CLOSE, 0, NULL);
}

void minigameStart() {
	printf("====================주사위 사칙연산 게임====================\n");
	for (int i = 0; i < 10; i++) {
		printf("player %d\n", i);
		throw_dice("숫자 주사위를 던지세요(press Enter)", threedice.dice1 = rand() % 6 + 1, "첫");
		throw_dice("연산기호 주사위를 던지세요(press Enter)", threedice.c = rand() % 4, "두");
		throw_dice("숫자 주사위를 던지세요(press Enter)", threedice.dice3 = rand() % 6 + 1, "세");

		if (threedice.c == 0) {
			threedice.score[i] = (double)threedice.dice1 + threedice.dice3;
		}
		else if (threedice.c == 1) {
			threedice.score[i] = (double)threedice.dice1 - threedice.dice3;
		}
		else if (threedice.c == 2) {
			threedice.score[i] = (double)threedice.dice1 * threedice.dice3;
		}
		else if (threedice.c == 3) {
			threedice.score[i] = (double)threedice.dice1 / threedice.dice3;
		}

		printf("결과값은 %lf 입니다.\n\n", threedice.score[i]);

		nextStep("계속 하려면 아무키나 누르십시오.");
	}
}

void minigameEnd() {
	printf("게임이 끝났습니다!!!\n");
	printf("이번 게임의 랭킹을 토대로 다음 게임의 순서가 정해집니다\n\n");

	nextStep("미니게임 결과를 확인하려면 아무키나 입력하십시오");

	printf("=========랭킹 1위부터 10위까지=========\n");
	g2_rankingOutput(threedice.score);

	nextStep("\n다음 게임을 시작하려면 아무키나 입력하십시오.");
}