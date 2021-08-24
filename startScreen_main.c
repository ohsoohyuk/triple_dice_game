#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "Allcommon.h"
#include "startScreen_main.h"
#include "startScreen_mainmenu.h"
//#include "bgm.h"

#define _CRT_SECURE_NO_WARNINGS

//메뉴화면
void menuscreen()
{
	//mainmenuBgm();

	initCursor();
	start();
	visiCursor();

	//mciSendCommand(menuBgm.wDeviceID, MCI_CLOSE, 0, NULL);
}

void initCursor() //초기화를 해주는 함수
{
	CONSOLE_CURSOR_INFO curinfor;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curinfor);
	curinfor.bVisible = FALSE;                            //커서를 안보이게 함
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curinfor);
}

void visiCursor() {
	CONSOLE_CURSOR_INFO curinfor;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curinfor);
	curinfor.bVisible = TRUE;                            //커서를 보이게 함
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curinfor);
}

void gotoxy(int x, int y)//커서를 이동시켜줌
{

	COORD pos = { x,y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}

void printfXY(int x, int y, char* msg)
{
	gotoxy(x, y);
	printf(msg);
}

void erasecursor()
{
	gotoxy(startcursor.x, startcursor.y);
	printf("  ");
}

void cursorsupply()
{
	gotoxy(startcursor.x, startcursor.y);
	printf("☞");
}