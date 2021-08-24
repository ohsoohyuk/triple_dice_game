#include <windows.h>
#include "startScreen_mainmenu.h"
#include "startScreen_howtoGame1.h"
#include "startScreen_howtoGame2.h"
#include "startScreen_howtoGame2.h"
#include "startScreen_howtoGame3.h"
#include "startScreen_main.h"
#include "startScreen_rulemenu.h"

void rule_menu() {
	system("cls");
	Sleep(200);
	startcursor.x = 8; startcursor.y = 13;
	cursorsupply();

	while (1)
	{
		printfXY(50, 1, "설명을 보고 싶은 게임을 선택하세요");

		printfXY(10, 13, "◑ 1번 주사위 굴리기 게임");;
		printfXY(10, 18, "◑ 2번 주사위 사칙연산 게임");
		printfXY(10, 23, "◑ 3번 주사위 윷놀이 게임");
		printfXY(10, 28, "◑ 메인 메뉴로 돌아가기");

		printfXY(5, 36, "방향키 : 이동 / 스페이스바 : 선택");

		if (GetAsyncKeyState(VK_DOWN) & 0X8000) {
			if (startcursor.y <= 23) {
				erasecursor();
				startcursor.y = startcursor.y + 5;
				cursorsupply();
				Sleep(200);
			}
			else {
				erasecursor();
				startcursor.y = 13;
				cursorsupply();
				Sleep(200);
			}
		}

		else if (GetAsyncKeyState(VK_UP) & 0X8000) {
			if (startcursor.y >= 18) {
				erasecursor();
				startcursor.y = startcursor.y - 5;
				cursorsupply();
				Sleep(200);
			}
			else {
				erasecursor();
				startcursor.y = 28;
				cursorsupply();
				Sleep(200);
			}
		}

		else if (GetAsyncKeyState(VK_SPACE) & 0X8000) {
			if (startcursor.y == 13) {
				howto_a1();
				break;
			}
			else if (startcursor.y == 18) {
				howto_b1();
				break;
			}
			else if (startcursor.y == 23) {
				howto_c1();
				break;
			}
			else if (startcursor.y == 28) {
				start();
				break;
			}
		}
	}
}