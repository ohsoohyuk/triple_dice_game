#pragma once
//공통으로 필요한 것
#define _CRT_SECURE_NO_WARNINGS
#define PLAYER 10         //플레이어 수를 나타내는 것

extern char temp;        //문자 입력 변수
extern char sequence[PLAYER];      //player문자 순서배열
extern int totalscore[PLAYER];  //종합게임점수
extern int mg_rank[PLAYER];     //미니게임 후 순서 저장 배열


int i_player_score_sort(int data[]);
int d_player_score_sort(double data[]);
void nextStep(char* pri);
void g2_rankingOutput(double rankoutput[]);
void g1g3_rankingOutput(int rankoutput[]);