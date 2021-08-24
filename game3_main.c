#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include "game3_main.h"
#include "game3_variable.h"
#include "Allcommon.h"
#include "game3_player_dice_rolling.h"
#include "fileio.h"
//#include "bgm.h"

void game3() {
	//maingame2_Bgm();

	for (int i = 0; i < 2; i++) {
		maingame2_rule();
		maingame2_start(i);
	}
	maingame2_end();
	
	//mciSendCommand(main2Bgm.wDeviceID, MCI_CLOSE, 0, NULL);
}

void maingame2_rule() {
	outputTotal("maingame2_rule.txt");
}

void maingame2_start(int hello) {
	nextStep("게임을 시작하시겠습니까?(아무 문자를 입력하세요): ");

	for (int i = 0; i <= 4; i++) {
		map[3][4 + i * 2] = sequence[mg_rank[hello * 5 + i]];
	}

	for (int i = 1; i <= 10; i++) {
		map_print(hello);

		if (i != 1 && i < 9) {
			printf("%d턴이 끝났습니다 ", i - 1);
		}
		else if (i == 10) {
			printf("%d턴이 끝났습니다 마지막 턴인 ", i - 1);
		}
		printf("%d턴을 시작합니다.\n\n", i);


		for (int j = 0; j < 5; j++) {
			if (game3Var.player[mg_rank[hello * 5 + j]] <= 40) {
				player_dice(hello, hello * 5 + j, hex_color[j]);
				system("cls");
				map_print(hello);
			}
		}

		system("cls");

		if (checkGameset(hello, i) == 1) {
			break;
		}
	}

	printf("메인게임2(주사위 윷놀이)의 %d번째 게임 결과를 발표하겠습니다.\n", hello + 1);

	for (int i = 0; i < 5; i++) {
		printf("player%c님 : %d점\n", sequence[mg_rank[hello * 5 + i]], game3Var.player[mg_rank[hello * 5 + i]]);
	}

	nextStep("\n다음 게임을 위해 아무키나 입력하십시오.");


	//다음 게임을 위해 이전게임에서 도착하지 못한 말들을 공백으로 초기화 시켜준다
	for (int i = 0; i < 5; i++) {
		map[game3Var.hei[hello * 5 + i]][game3Var.wid[hello * 5 + i]] = ' ';
	}
}

void maingame2_end() {
	for (int i = 0; i < PLAYER; i++) {
		totalscore[i] += game3Var.player[i];
	}

	printf("==========메인게임2(주사위 윷놀이)의 전체 게임 랭킹==========\n");
	g1g3_rankingOutput(game3Var.player);

	nextStep("\n모든 게임이 종료되었습니다!! 최종 결과를 확인하려면 아무키나 입력하십시오.");

	//	mciSendCommand(main2Bgm.wDeviceID, MCI_CLOSE, 0, NULL);
}

int checkGameset(int hello, int i) {
	int he_sum = 0;

	for (int j = 0; j < 5; j++) {
		if (game3Var.player[mg_rank[hello * 5 + j]] > 40) {
			he_sum++;
		}
	}


	//게임이 끝날 때
	if (he_sum == 4 && i != 10) {
		printf("1명을 제외하고 4명의 player가 %d턴만에 도착지점에 도착하였습니다. 게임을 일찍 종료합니다\n\n", i);

		return 1;
	} // 플레이어 1명을 제외하고 4명의 플레이어가 10턴전에 도착할 시
	else if (he_sum == 5) {
		printf("모든 player가 %d턴만에 도착지점에 도착하였습니다. 게임을 일찍 종료합니다\n\n", i);

		return 1;
	} // 플레이어들 전부 10턴 전에 도착할시
	else if (i == 10) {
		printf("마지막턴이 끝났습니다. 게임을 종료합니다.\n\n");

		if (he_sum > 0) {
			printf("%d명을 제외하고 %d명의 player가 도착지점에 도착하였습니다.\n\n", 5 - he_sum, he_sum);
		}
		else {
			printf("아무도 도착지점에 도착하지 못하였습니다.\n\n");
		}

		return 1;
	}

	return 0;
}

void map_print(int hello) {
	for (int i = 0; i < 38; i++) {
		for (int j = 0; j < 78; j++) {
			if ((map[i][j] == sequence[mg_rank[hello * 5]] && map[i - 1][j + 1] == ' ') ||
				(map[i][j] == sequence[mg_rank[hello * 5]] && map[i - 1][j + 1] == '(')) {
				RED; printf("%c", map[i][j]);
			}
			else if ((map[i][j] == sequence[mg_rank[hello * 5 + 1]] && map[i - 1][j + 1] == ' ') ||
				(map[i][j] == sequence[mg_rank[hello * 5 + 1]] && map[i - 1][j - 1] == '(')) {
				VIOLET; printf("%c", map[i][j]);
			}
			else if ((map[i][j] == sequence[mg_rank[hello * 5 + 2]] && map[i - 1][j + 1] == ' ') ||
				(map[i][j] == sequence[mg_rank[hello * 5 + 2]] && map[i - 1][j - 3] == '(')) {
				YELLOW; printf("%c", map[i][j]);
			}
			else if ((map[i][j] == sequence[mg_rank[hello * 5 + 3]] && map[i - 1][j + 1] == ' ') ||
				(map[i][j] == sequence[mg_rank[hello * 5 + 3]] && map[i - 1][j - 5] == '(')) {
				GREEN; printf("%c", map[i][j]);
			}
			else if ((map[i][j] == sequence[mg_rank[hello * 5 + 4]] && map[i - 1][j + 1] == ' ') ||
				(map[i][j] == sequence[mg_rank[hello * 5 + 4]] && map[i - 1][j - 7] == '(')) {
				BLUE; printf("%c", map[i][j]);
			}
			else {
				WHITE; printf("%c", map[i][j]);
			}
		}
		printf("\n");
	}
}