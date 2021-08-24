#pragma once
#include "Allcommon.h"

void minigame();
void minigame_rule();
void minigameStart();
void minigameEnd();

typedef struct {
	int dice1, c, dice3;
	char dice2[4];
	double score[PLAYER];
}game2;

game2 threedice;