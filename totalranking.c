#include <stdio.h>
#include "totalranking.h"
#include "Allcommon.h"
#include "game3_variable.h"
#include "game1_main.h"

void outputTotalranking() {
	printf("===============종합 게임 랭킹===============\n");
	g1g3_rankingOutput(totalscore);

	nextStep("\n아무키나 입력하시면 처음으로 돌아갑니다. ");
}