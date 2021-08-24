/*#pragma once
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")             //사운드 출력함수
#include <Digitalv.h>
#include <Windows.h>

MCI_OPEN_PARMS menuBgm;
MCI_PLAY_PARMS menu2Bgm;
MCI_OPEN_PARMS main1Bgm;
MCI_PLAY_PARMS play1Bgm;
MCI_OPEN_PARMS miniBgm;
MCI_PLAY_PARMS playBgm;
MCI_OPEN_PARMS main2Bgm;
MCI_PLAY_PARMS play2Bgm;
MCI_OPEN_PARMS openShuffleSound;
MCI_PLAY_PARMS playShuffleSound;

//bgm 경로를 바꾸어 주어야지 bgm이 들림
#define bgm0 "C:\\Users\\osh\\source\\repos\\Project3\\Project3\\bgm\\메뉴음악.mp3"
#define bgm1 "C:\\Users\\osh\\source\\repos\\Project3\\Project3\\bgm\\메인게임1음악.mp3"
#define bgm2 "C:\\Users\\osh\\source\\repos\\Project3\\Project3\\bgm\\미니게임음악.mp3"
#define bgm3 "C:\\Users\\osh\\source\\repos\\Project3\\Project3\\bgm\\메인게임2음악.mp3"
#define shuffle "C:\\Users\\osh\\source\\repos\\Project3\\Project3\\bgm\\주사위굴리는소리.mp3"

int dwID;
void mainmenuBgm();
void maingame1_Bgm();
void minigame_Bgm();
void maingame2_Bgm();
void playingShuffleSound();*/