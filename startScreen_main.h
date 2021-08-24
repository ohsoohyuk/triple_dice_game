#pragma once
typedef struct {
	int x;
	int y;
}obj;

obj startcursor;//메뉴용 커서

void menuscreen();
void printfXY(int x, int y, char* msg);
void erasecursor();//커서지우기
void cursorsupply();//커서적용
void initCursor();
void visiCursor();