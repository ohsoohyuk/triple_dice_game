/*#include "bgm.h"

//배경음악
void mainmenuBgm() {
	menuBgm.lpstrElementName = bgm0; //파일 오픈
	menuBgm.lpstrDeviceType = "mpegvideo"; //mp3 형식
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&menuBgm);
	dwID = menuBgm.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&menuBgm); //음악 반복 재생
}

void maingame1_Bgm() {
	main1Bgm.lpstrElementName = bgm1; //파일 오픈
	main1Bgm.lpstrDeviceType = "mpegvideo"; //mp3 형식
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&main1Bgm);
	dwID = main1Bgm.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&main1Bgm); //음악 반복 재생
}

void minigame_Bgm() {
	miniBgm.lpstrElementName = bgm2; //파일 오픈
	miniBgm.lpstrDeviceType = "mpegvideo"; //mp3 형식
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&miniBgm);
	dwID = miniBgm.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&miniBgm); //음악 반복 재생
}

void maingame2_Bgm() {
	main2Bgm.lpstrElementName = bgm3; //파일 오픈
	main2Bgm.lpstrDeviceType = "mpegvideo"; //mp3 형식
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&main2Bgm);
	dwID = main2Bgm.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&main2Bgm); //음악 반복 재생
}

void playingShuffleSound() {
	openShuffleSound.lpstrElementName = shuffle; //파일 오픈
	openShuffleSound.lpstrDeviceType = "mpegvideo"; //mp3 형식
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openShuffleSound);
	dwID = openShuffleSound.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openShuffleSound); //음악을 한 번 재생
	Sleep(500);
	mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
}*/