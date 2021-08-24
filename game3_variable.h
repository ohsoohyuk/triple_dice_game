#pragma once
#include <Windows.h>

#define col GetStdHandle(STD_OUTPUT_HANDLE)
#define RED SetConsoleTextAttribute(col,0x000c);          //첫번째 빨간색
#define VIOLET SetConsoleTextAttribute(col,0x000d);       //두번째 자주색
#define YELLOW SetConsoleTextAttribute(col,0x000e);       //세번째 노란색
#define GREEN SetConsoleTextAttribute(col,0x000a);        //네번째 초록색
#define BLUE SetConsoleTextAttribute(col,0x0009);         //다섯째 파란색
#define WHITE SetConsoleTextAttribute(col,0x000f);

typedef struct Route {
	int base_route[21];
	int route1[13];
	int route2[17];
	int route3[23];
}Route;

typedef struct Game3 {
	int sumdice[10];
	int player[10];
	int hei[10];
	int wid[10];
	int score;
	int dice;
}Game3;

Route route;
Game3 game3Var;

extern char map[][100];
extern int hex_color[];