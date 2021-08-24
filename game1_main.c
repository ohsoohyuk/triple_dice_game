#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <conio.h>
#include <windows.h>
#include "Allcommon.h"
#include "game1_main.h"
#include "game1_calculate_score.h"
#include "game1_dice_rolling.h"
#include "game1_time_count.h"
#include "fileio.h"
//#include "bgm.h"

void game1() {
	//maingame1_Bgm();

	maingame1_rule();
	maingame1_start();
	maingame1_end();

	//mciSendCommand(main1Bgm.wDeviceID, MCI_CLOSE, 0, NULL);
}

//메인게임1
void maingame1_rule() {
	outputTotal("maingame1_rule.txt");
}

void maingame1_start() {
	nextStep("게임을 시작하시겠습니까?(아무 문자나 입력하십시오) : ");

	srand((unsigned int)time(NULL));

	//N, M, K 값은 플레이어 전부 똑같기 때문에 초기에 값을 넣어줌
	play.N = rand() % 5 + 1;
	play.M = rand() % 10 + 1;
	play.K = rand() % 20 + 1;

	for (int i = 0; i < PLAYER; i++) {
		printf("player%d님 시작하십시오.(아무 문자나 입력하시오. 입력시에 바로 문제가 나오고 시간초가 지납니다) : ", i);
		temp = getchar();
		while (temp = getchar() != '\n' && temp != EOF);

		//수 생성
		int** board = createValue();
		
		//문제 푼 시간 저장
		time_count(board, i);

		//맞은정답 점수 계산
		correctCalScore(i);

		free(board);
	}

	//시간순서 추가점수 계산
	timeCalScore();
}

void maingame1_end() {

	for (int i = 0; i < PLAYER; i++) {
		totalscore[i] += play.score[i];
	}

	nextStep("메인게임 주사위 굴리기가 종료되었습니다. 게임 결과를 확인하려면 아무키나 입력하십시오.");

	printf("============랭킹 1위부터 10위까지============\n");
	g1g3_rankingOutput(play.score);

	nextStep("\n다음 게임을 진행하려면 아무키나 입력하십시오.");
}

int** createValue() {
	play.x = rand() % play.M;
	play.y = rand() % play.N;

	int** board = (int**)malloc(sizeof(int*) * 100);
	for (int i = 0; i < play.N; i++) {
		board[i] = (int*)malloc(sizeof(int) * 100);
	}

	printf("\n%d %d %d %d %d\n", play.N, play.M, play.x, play.y, play.K);

	for (int i = 0; i < play.N; i++) {
		for (int j = 0; j < play.M; j++) {
			if (i == play.y && j == play.x) {
				board[i][j] = 0;
			}
			else {
				board[i][j] = rand() % 10;
			}

			printf("%d ", board[i][j]);
		}

		printf("\n");
	}

	return board;
}