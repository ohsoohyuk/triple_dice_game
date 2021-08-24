#include <stdio.h>
#include "Allcommon.h"
#include "game1_main.h"
#include "game1_calculate_score.h"

void correctCalScore(int playernumber) {
	if (play.result == 6) {
		printf("\nplayer%d님은 모든 면을 맞추셨습니다. 점수는 %d점 입니다.\n", playernumber, play.result * 10 + 10);
		play.score[playernumber] = play.result * 10 + 10;
	}
	else {
		printf("player%d님은 총 %d면을 맞추셨습니다. 점수는 %d점 입니다.\n\n", playernumber, play.result, play.result * 10);
		play.score[playernumber] = play.result * 10;
	}

	printf("player%d님이 걸린 시간은 : %.3lf초 입니다.\n\n", playernumber, play.duration[playernumber]);

	//다음 플레이어를 위해 결과값 초기화
	play.result = 0;
}

void timeCalScore() {
	for (int i = 0; i < PLAYER; i++) {
		int most = d_player_score_sort(play.duration);

		play.duration[most] = -1.0;         //큰수를 순서대로 꺼내기 위해서 먼저 꺼낸 인덱스에 0초 미만의 값을 넣어줌

		if (i <= 5) {
			play.score[most] += 5;
		}
		else if (i == 6) {
			play.score[most] += 10;
		}
		else if (i == 7) {
			play.score[most] += 12;
		}
		else if (i == 8) {
			play.score[most] += 15;
		}
		else if (i == 9) {
			play.score[most] += 20;
		}
	}
}