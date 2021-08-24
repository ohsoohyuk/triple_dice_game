#include <windows.h>
#include "fileio.h"
#include "game3_variable.h"
#include "startScreen_main.h"
#include "startScreen_howtoGame3.h"
#include "startScreen_mainmenu.h"
#include "startScreen_rulemenu.h"

void howto_c1()
{
	system("cls");
	Sleep(200);

	while (1)
	{
		printfXY(50, 1, "HOW TO PLAY DICE GAME");

		outputLine(2, 6, 0, 3, "startscreen_howto_c1.txt");

		printfXY(105, 1, "주사위 윷놀이의 게임판 입니다.");

		for (int i = 3; i <= 40; i++) {
			printfXY(85, i, map[i - 3]);
		}

		printfXY(5, 40, "○다음 페이지 = 스페이스바");
		printfXY(5, 42, "○이전 페이지 = x");
		printfXY(5, 44, "○메인 메뉴로 돌아가기 = z");

		if (GetAsyncKeyState(VK_SPACE) & 0X8000) {
			howto_c2();
			break;
		}
		else if (GetAsyncKeyState(0x58) & 0X8000) {
			rule_menu();
			break;
		}
		else if (GetAsyncKeyState(0x5A) & 0X8000) {
			start();
			break;
		}
	}
}

void howto_c2() {
	system("cls");
	Sleep(200);

	while (1) {
		printfXY(50, 1, "HOW TO PLAY DICE GAME");

		outputLine(2, 6, 0, 3, "startscreen_howto_c2.txt");

		printfXY(5, 42, "○이전 페이지 = x");
		printfXY(5, 44, "○메인 메뉴로 돌아가기 = z");

		if (GetAsyncKeyState(0x58) & 0X8000) {
			howto_c1();
			break;
		}
		else if (GetAsyncKeyState(0x5A) & 0X8000) {
			start();
			break;
		}
	}
}