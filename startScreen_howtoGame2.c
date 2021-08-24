#include <Windows.h>
#include "startScreen_howtoGame2.h"
#include "startScreen_rulemenu.h"
#include "startScreen_mainmenu.h"
#include "startScreen_main.h"
#include "fileio.h"

void howto_b1()
{
	system("cls");
	Sleep(200);

	while (1)
	{
		printfXY(50, 1, "HOW TO PLAY DICE GAME");

		outputLine(2, 6, 0, 4, "startscreen_howto_b1.txt");

		printfXY(5, 42, "○이전 페이지 = x");
		printfXY(5, 44, "○메인 메뉴로 돌아가기 = z");

		if (GetAsyncKeyState(0x58) & 0X8000) {
			rule_menu();
			break;
		}
		else if (GetAsyncKeyState(0x5A) & 0X8000) {
			start();
			break;
		}

	}
}