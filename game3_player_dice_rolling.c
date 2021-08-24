#include <stdio.h>
#include "Allcommon.h"
#include "game3_player_dice_rolling.h"
#include "game3_variable.h"
#include "game3_main.h"
//#include "bgm.h"

void player_dice(int hello, int g3_index, int color) {
	SetConsoleTextAttribute(col, color); printf("player%c님 ", sequence[mg_rank[g3_index]]);

	WHITE;  printf("주사위를 굴리십시오(아무 문자를 입력하세요): ");
	temp = getchar();
	while (temp = getchar() != '\n' && temp != EOF);   //버퍼를 비우는 코드
	//whlie문을 실행했을 때 일단 버퍼에 있는 것을 c로 받고 버퍼에 \n(개행)이 들어있거나 또는 EOF로 끝인지를 체크하여
	//끝을 만날 때까지 반복문으로 버퍼를 비웁니다

	printf("주사위가 몇이 나오는지 계산중입니다");
	//playingShuffleSound();

	for (int i = 0; i < 3; i++) {
		printf(".");
		Sleep(500);
	}
	system("cls");

	game3Var.dice = rand() % 5 + 1;
	game3Var.sumdice[mg_rank[g3_index]] += game3Var.dice;

	player_location(g3_index, hello);

	printf("\n다음 플레이어의 시작을 위해 아무 문자를 입력 해주십시오.");
	temp = getchar();
	while (temp = getchar() != '\n' && temp != EOF);   //버퍼를 비우는 코드
}

void player_location(int g3_index, int hello) {

	//주사위 굴리기전 위치 공백으로 초기화
	map[game3Var.hei[g3_index]][game3Var.wid[g3_index]] = ' ';

	//route1
	for (int i = 5; i <= 12; i++) {
		if (game3Var.sumdice[mg_rank[g3_index]] == 5 || (game3Var.sumdice[mg_rank[g3_index]] == i + game3Var.dice && game3Var.player[mg_rank[g3_index]] == route.route1[i])) {
			moveRoute1(g3_index, hello);
			return;
		}
	}

	//route2
	for (int i = 10; i <= 16; i++) {
		if (game3Var.sumdice[mg_rank[g3_index]] == 10 || (game3Var.sumdice[mg_rank[g3_index]] == i + game3Var.dice && game3Var.player[mg_rank[g3_index]] == route.route2[i])) {
			moveRoute2(g3_index, hello);
			return;
		}
	}

	//route3
	for (int i = 15; i <= 22; i++) {
		if (game3Var.sumdice[mg_rank[g3_index]] == 15 || (game3Var.sumdice[mg_rank[g3_index]] == i + game3Var.dice && game3Var.player[mg_rank[g3_index]] == route.route3[i])) {
			moveRoute3(g3_index, hello);
			return;
		}
	}

	//base_route
	moveBaseRoute(g3_index, hello);
}

void moveRoute1(int g3_index, int hello) {
	//도착했을때
	if (game3Var.sumdice[mg_rank[g3_index]] > 12) {
		map_print(hello);

		printf("나온 숫자는 %d 입니다 %d 만큼 이동합니다.\n", game3Var.dice, game3Var.dice);
		printf("player%c님이 도착하셨습니다! player%c님은 게임에서 제외됩니다.\n\n", sequence[mg_rank[g3_index]], sequence[mg_rank[g3_index]]);

		game3Var.score -= 2;

		game3Var.player[mg_rank[g3_index]] = (game3Var.score + 2);

		return;
	}
	//루트1에서 오른쪽
	else if (game3Var.sumdice[mg_rank[g3_index]] >= 5 && game3Var.sumdice[mg_rank[g3_index]] <= 9) {
		game3Var.hei[g3_index] = 23;
		game3Var.wid[g3_index] = 8 * (game3Var.sumdice[mg_rank[g3_index]] - 4) - 2;             //등차수열공식 a+(n-1)d
	}
	//루트1에서 위쪽
	else {
		game3Var.hei[g3_index] = -4 * (game3Var.sumdice[mg_rank[g3_index]] - 9) + 23;
		game3Var.wid[g3_index] = 38;
	}

	game3Var.player[mg_rank[g3_index]] = route.route1[game3Var.sumdice[mg_rank[g3_index]]];


	Catch_player(g3_index, hello);

	if (game3Var.sumdice[mg_rank[g3_index]] == 5) {
		printf("route1에 진입합니다.\n");
	}
	printf("player%c님의 위치는 route1의 %d 입니다.\n\n", sequence[mg_rank[g3_index]], game3Var.player[mg_rank[g3_index]]);
}

void moveRoute2(int g3_index, int hello) {
	//도착했을때
	if (game3Var.sumdice[mg_rank[g3_index]] > 16) {
		map_print(hello);
		printf("나온 숫자는 %d 입니다 %d 만큼 이동합니다.\n", game3Var.dice, game3Var.dice);
		printf("player%c님이 도착하셨습니다! player%c님은 게임에서 제외됩니다.\n\n", sequence[mg_rank[g3_index]], sequence[mg_rank[g3_index]]);

		game3Var.score -= 2;

		game3Var.player[mg_rank[g3_index]] = (game3Var.score + 2);

		return;
	}
	//루트2에서 위쪽
	else if (game3Var.sumdice[mg_rank[g3_index]] >= 10 && game3Var.sumdice[mg_rank[g3_index]] <= 16) {
		game3Var.hei[g3_index] = -4 * (game3Var.sumdice[mg_rank[g3_index]] - 10) + 35;
		game3Var.wid[g3_index] = 38;
	}

	game3Var.player[mg_rank[g3_index]] = route.route2[game3Var.sumdice[mg_rank[g3_index]]];


	Catch_player(g3_index, hello);

	if (game3Var.sumdice[mg_rank[g3_index]] == 10) {
		printf("route2에 진입합니다.\n");
	}
	printf("player%c님의 위치는 route2의 %d 입니다.\n\n", sequence[mg_rank[g3_index]], game3Var.player[mg_rank[g3_index]]);
}

void moveRoute3(int g3_index, int hello) {
	if (game3Var.sumdice[mg_rank[g3_index]] > 22) {
		map_print(hello);
		printf("나온 숫자는 %d 입니다 %d 만큼 이동합니다.\n", game3Var.dice, game3Var.dice);
		printf("player%c님이 도착하셨습니다! player%c님은 게임에서 제외됩니다.\n\n", sequence[mg_rank[g3_index]], sequence[mg_rank[g3_index]]);

		game3Var.score -= 2;

		game3Var.player[mg_rank[g3_index]] = (game3Var.score + 2);

		return;
	}
	//루트3에서 왼쪽
	else if (game3Var.sumdice[mg_rank[g3_index]] >= 15 && game3Var.sumdice[mg_rank[g3_index]] <= 19) {
		game3Var.hei[g3_index] = 23;
		game3Var.wid[g3_index] = -8 * (game3Var.sumdice[mg_rank[g3_index]] - 14) + 78;
	}
	//루트3에서 위쪽
	else {
		game3Var.hei[g3_index] = -4 * (game3Var.sumdice[mg_rank[g3_index]] - 19) + 23;
		game3Var.wid[g3_index] = 38;
	}

	game3Var.player[mg_rank[g3_index]] = route.route3[game3Var.sumdice[mg_rank[g3_index]]];


	Catch_player(g3_index, hello);

	if (game3Var.sumdice[mg_rank[g3_index]] == 15) {
		printf("route3에 진입합니다.\n");
	}
	printf("player%c님의 위치는 route3의 %d 입니다.\n\n", sequence[mg_rank[g3_index]], game3Var.player[mg_rank[g3_index]]);
}

void moveBaseRoute(int g3_index, int hello) {
	if (game3Var.sumdice[mg_rank[g3_index]] > 20) {
		map_print(hello);
		printf("나온 숫자는 %d 입니다 %d 만큼 이동합니다.\n", game3Var.dice, game3Var.dice);
		printf("player%c님이 도착하셨습니다! player%c님은 게임에서 제외됩니다.\n\n", sequence[mg_rank[g3_index]], sequence[mg_rank[g3_index]]);

		game3Var.score -= 2;

		game3Var.player[mg_rank[g3_index]] = (game3Var.score + 2);

		return;
	}
	//밑 이동
	else if (game3Var.sumdice[mg_rank[g3_index]] >= 1 && game3Var.sumdice[mg_rank[g3_index]] <= 4) {
		game3Var.hei[g3_index] = 4 * game3Var.sumdice[mg_rank[g3_index]] + 3;
		game3Var.wid[g3_index] = 6;
	}
	//오른쪽밑 이동
	else if (game3Var.sumdice[mg_rank[g3_index]] >= 6 && game3Var.sumdice[mg_rank[g3_index]] <= 9) {
		game3Var.hei[g3_index] = 2 * (game3Var.sumdice[mg_rank[g3_index]] - 5) + 25;
		game3Var.wid[g3_index] = 7 * (game3Var.sumdice[mg_rank[g3_index]] - 5) + 2;
	}
	//오른쪽위 이동
	else if (game3Var.sumdice[mg_rank[g3_index]] >= 11 && game3Var.sumdice[mg_rank[g3_index]] <= 14) {
		game3Var.hei[g3_index] = -2 * (game3Var.sumdice[mg_rank[g3_index]] - 10) + 35;
		game3Var.wid[g3_index] = 7 * (game3Var.sumdice[mg_rank[g3_index]] - 10) + 39;
	}
	//왼쪽위 이동
	else if (game3Var.sumdice[mg_rank[g3_index]] >= 16 && game3Var.sumdice[mg_rank[g3_index]] <= 19) {
		game3Var.hei[g3_index] = -2 * (game3Var.sumdice[mg_rank[g3_index]] - 15) + 21;
		game3Var.wid[g3_index] = -7 * (game3Var.sumdice[mg_rank[g3_index]] - 15) + 74;
	}
	else if (game3Var.sumdice[mg_rank[g3_index]] == 20) {
		game3Var.hei[g3_index] = 11;
		game3Var.wid[g3_index] = 38;
	}

	game3Var.player[mg_rank[g3_index]] = route.base_route[game3Var.sumdice[mg_rank[g3_index]]];

	Catch_player(g3_index, hello);

	printf("player%c님의 위치는 base_route의 %d 입니다.\n\n", sequence[mg_rank[g3_index]], game3Var.player[mg_rank[g3_index]]);
}

void Catch_player(int g3_index, int hello) {
	for (int i = 0; i < 5; i++) {
		if (g3_index != hello * 5 + i && game3Var.hei[g3_index] == game3Var.hei[hello * 5 + i] && game3Var.wid[g3_index] == game3Var.wid[hello * 5 + i] && game3Var.player[mg_rank[hello * 5 + i]] <= 40) {

			//점수, 합산주사위값 초기화
			game3Var.player[mg_rank[hello * 5 + i]] = 0;
			game3Var.sumdice[mg_rank[hello * 5 + i]] = 0;

			//말 index 초기화
			game3Var.hei[hello * 5 + i] = 3;
			game3Var.wid[hello * 5 + i] = 4 + i * 2;

			//잡힌 말 위치 초기화
			map[3][4 + i * 2] = sequence[mg_rank[hello * 5 + i]];

			//말 이동
			map[game3Var.hei[g3_index]][game3Var.wid[g3_index]] = sequence[mg_rank[g3_index]];

			map_print(hello);
			printf("나온 숫자는 %d 입니다 %d 만큼 이동합니다.\n", game3Var.dice, game3Var.dice);

			printf("player%c님이 player%c님의 말을 잡았습니다. player%c님은 시작지점으로 되돌아갑니다.\n", sequence[mg_rank[g3_index]], sequence[mg_rank[hello * 5 + i]], sequence[mg_rank[hello * 5 + i]]);

			return;
		}
	}

	//말 이동
	map[game3Var.hei[g3_index]][game3Var.wid[g3_index]] = sequence[mg_rank[g3_index]];

	map_print(hello);
	printf("나온 숫자는 %d 입니다 %d 만큼 이동합니다.\n", game3Var.dice, game3Var.dice);
}