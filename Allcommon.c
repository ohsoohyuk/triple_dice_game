#include <stdio.h>
#include <stdlib.h>
#include "Allcommon.h"

char temp;        //문자 입력 변수
char sequence[PLAYER] = { '0','1', '2', '3','4','5','6','7','8','9' };      //player문자 순서배열
int totalscore[PLAYER];  //종합게임점수
int mg_rank[PLAYER] = { 0, };     //미니게임 후 순서 저장 배열


//정수형 큰배열수 index 뽑아내기 
int i_player_score_sort(int data[]) {
	int most = 0;
	int start = 0;
	
	for (int i = start + 1; i < PLAYER; i++) {
		if (data[i] > data[most]) {
			most = i;
		}
	}

	return most;
}

//실수형 큰배열수 index 뽑아내기
int d_player_score_sort(double data[]) {
	int most = 0;
	int start = 0;

	for (int i = start + 1; i < PLAYER; i++) {
		if (data[i] > data[most]) {
			most = i;
		}
	}

	return most;
}

void nextStep(char* pri) {
	printf("%s", pri);
	temp = getchar();
	while (temp = getchar() != '\n' && temp != EOF);
	system("cls");
}

void g2_rankingOutput(double rankOutput[]) {
	for (int i = 0; i < PLAYER; i++) {
		int most = d_player_score_sort(rankOutput);

		printf("%d등 = player%d의 점수 : %lf\n", i + 1, most, rankOutput[most]);
		mg_rank[i] = most;			   //주사위 굴리기 게임에서 시작될 player의 순서
		rankOutput[most] = -100;  //겹치는 부분이 있으면 안되므로 아무 변수나 넣어줌
	}
}

void g1g3_rankingOutput(int rankOutput[]) {
	for (int i = 0; i < PLAYER; i++) {
		int most = i_player_score_sort(rankOutput);

		printf("%d등 = player%d의 점수 : %d\n", i + 1, most, rankOutput[most]);
		rankOutput[most] = -100;  //겹치는 부분이 있으면 안되므로 아무 변수나 넣어줌
	}
}