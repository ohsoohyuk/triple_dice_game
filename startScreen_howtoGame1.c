#include <Windows.h>
#include "fileio.h"
#include "startScreen_howtoGame2.h"
#include "startScreen_mainmenu.h"
#include "startScreen_rulemenu.h"
#include "startScreen_howtoGame1.h"
#include "startScreen_main.h"

void howto_a1()
{
	system("cls");
	Sleep(200);

	while (1)
	{
		printfXY(50, 1, "HOW TO PLAY DICE GAME");

		outputLine(2, 6, 0, 3, "startscreen_howto_a1.txt");

		printfXY(5, 40, "○다음 페이지 = 스페이스바");
		printfXY(5, 42, "○이전 페이지 = x");
		printfXY(5, 44, "○메인 메뉴로 돌아가기 = z");

		if (GetAsyncKeyState(VK_SPACE) & 0X8000) {
			howto_a2();
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

void howto_a2()
{
	system("cls");
	Sleep(200);

	while (1)
	{
		printfXY(45, 1, "HOW TO PLAY DICE GAME");

		outputLine(2, 9, 0, 3, "startscreen_howto_a2.txt");

		printfXY(5, 40, "○다음 페이지 = 스페이스바");
		printfXY(5, 42, "○이전 페이지 = x");
		printfXY(5, 44, "○메인 메뉴로 돌아가기 = z");

		if (GetAsyncKeyState(VK_SPACE) & 0X8000) {
			howto_a3();
			break;
		}
		else if (GetAsyncKeyState(0x58) & 0X8000) {
			howto_a1();
			break;
		}
		else if (GetAsyncKeyState(0x5A) & 0X8000) {
			start();
			break;
		}
	}
}

void howto_a3()
{
	system("cls");
	Sleep(200);

	while (1)
	{
		printfXY(45, 1, "HOW TO PLAY DICE GAME");

		outputLine(2, 6, 0, 3, "startscreen_howto_a3.txt");

		outputLine(5, 21, 0, 1, "game1_dice.txt");

		printfXY(5, 42, "○이전 페이지 = x");
		printfXY(5, 44, "○메인 메뉴로 돌아가기 = z");

		if (GetAsyncKeyState(0x58) & 0X8000) {
			howto_a2();
			break;
		}
		else if (GetAsyncKeyState(0x5A) & 0X8000) {
			start();
			break;
		}
	}
}