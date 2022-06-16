#include <io.h>
#include <fcntl.h>
#include<iomanip> 
#include"Console.h"
#include "Stage.h"
using namespace std;
char stageMap[HEIGHT][WEIGHT];
int main() {
	setColor(0, 7);
	system("cls");
	PLAYER tPlayer;
	int stage;
	cout << "타이틀 미정" << endl;
	cout << "Press Any Key To Start" << endl;
	_getch();
	while (true) {
		system("cls");
		cout << "STAGE 1" << endl << "STAGE 2" << endl << "STAGE 3" << endl;
		cout << "번호를 입력하여 스테이지를 선택하세요 (0 - 종료, 9 - 설명):";
		cin >> stage;
		if (stage == 0) { break; }
		else if (stage == 9) {
			system("cls");
			cout << "\t\t\t게임 설명" << endl << endl;
			cout << "\t조작" << endl << endl << "space, ↑ - 점프" << endl << "↓ - 웅크리기" << endl << endl << endl;
			cout << "\t아이템" << endl << endl;
			setColor(6, 7);
			cout << "★";
			setColor(0, 7);
			cout << " - 무적" << endl;
			setColor(12, 7);
			cout << "♡";
			setColor(0, 7);
			cout << " - HP 업" << endl;
			setColor(4, 7);
			cout << "♬";
			setColor(0, 7);
			cout << "/";
			setColor(1, 7);
			cout << "♬";
			setColor(0, 7);
			cout << " - 스피드 업/다운" << endl << endl << endl;
			cout << "키를 누르면 스테이지 선택 화면으로 되돌아 갑니다." << endl;
			_getch();
			continue;
		}
		SetStage(stage, stageMap);
		CreateItem(stageMap);
		SetNewGame(&tPlayer);
		while (true)
		{
			system("cls");

			if (CheckEnd(&tPlayer))
			{
				cout << "STAGE " << stage << " CLEAR!" << endl;
				cout << "3초 후에 스테이지 선택 화면으로 되돌아갑니다." << endl;
				cout << "3... "; Sleep(1000);
				cout << "2... "; Sleep(1000);
				cout << "1... "; Sleep(1000);
				break;
			}
			else if (CheckHp(&tPlayer)) {
				cout << "GAME OVER!" << endl;
				cout << "3초 후에 스테이지 선택 화면으로 되돌아갑니다." << endl;
				cout << "3... "; Sleep(1000);
				cout << "2... "; Sleep(1000);
				cout << "1... "; Sleep(1000);
				break;
			}

			SetPlayerJump(&tPlayer);
			SetPlayerItem(&tPlayer);
			PrintStage(stageMap, &tPlayer);
			SetPlayerDown(&tPlayer);
			char cinput = GetKeyDown();
			if (cinput == 'q' || cinput == 'Q') {
				break;
			}
			MovePlayer(&tPlayer);
			MoveRight(stageMap, &tPlayer);
			Sleep(speed);
		}
	}
}