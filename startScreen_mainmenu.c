#include <Windows.h>
#include "startScreen_rulemenu.h"
#include "startScreen_mainmenu.h"
#include "startScreen_main.h"

void start() {
	system("cls");
	Sleep(200);
	startcursor.x = 8, startcursor.y = 13;
	cursorsupply();

	while (1)
	{

		printfXY(15, 6, "▣=============================== 주 사 위 게 임 ===============================▣");

		printfXY(10, 13, "◑ 게임 시작");
		printfXY(10, 16, "◑ 게임 설명");
		printfXY(10, 19, "◑ 종료");

		printfXY(5, 36, "방향키 : 이동 / 스페이스바 : 선택");

		//아래키 눌렀을시
		if (GetAsyncKeyState(VK_DOWN) & 0X8000) {
			if (startcursor.y <= 16) {
				erasecursor();
				startcursor.y = startcursor.y + 3;
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

		//윗키 눌렀을시
		else if (GetAsyncKeyState(VK_UP) & 0X8000) {
			if (startcursor.y >= 16) {
				erasecursor();
				startcursor.y = startcursor.y - 3;
				cursorsupply();
				Sleep(200);
			}
			else {
				erasecursor();
				startcursor.y = 19;
				cursorsupply();
				Sleep(200);
			}
		}

		//스페이스 눌렀을시
		else if (GetAsyncKeyState(VK_SPACE)) {
			if (startcursor.y == 13) {
				system("cls");
				return;
			}
			else if (startcursor.y == 16) {
				rule_menu();
			}
			else if (startcursor.y == 19) {
				exit(0);
			}
		}
	}
}