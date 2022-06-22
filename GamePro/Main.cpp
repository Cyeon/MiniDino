#include <io.h>
#include <fcntl.h>
#include<iomanip> 
#include"Console.h"
#include "Stage.h"
using namespace std;
char stageMap[HEIGHT][WEIGHT];
int main() {
	system("mode con cols=70 lines=15");
	PlayingBgm();
	CursorHide();
	setColor(0, 7);
	system("cls");
	PLAYER tPlayer;
	int stage;
	_setmode(_fileno(stdout), _O_U8TEXT);
	wcout << L"           __       __        __ __             " << endl;
	wcout << L" .--------|__.-----|__|   .--|  |__.-----.-----." << endl;
	wcout << L" |        |  |     |  |   |  _  |  |     |  _  |" << endl;
	wcout << L" |__|__|__|__|__|__|__|   |_____|__|__|__|_____|" << endl;
	_setmode(_fileno(stdout), O_TEXT);
	cout << endl << "Press Any Key To Start" << endl;
	_getch();
	while (true) {
		system("cls");
		if (!gameClear && CheckGameEnd()) {
			cout << "축하합니다 모든 스테이지를 클리어하셨습니다." << endl;
			cout << "플레이 해주셔서 감사합니다." << endl;
			cout << "키를 누르면 스테이지 클리어 화면으로 돌아갑니다." << endl;
			_getch();
			system("cls");
			gameClear = true;
		}
		cout << stageClear[0] << stageClear[1] << stageClear[2] << endl;
		cout << gameClear << CheckGameEnd() << endl << endl;
		cout << "STAGE 1" << endl << "STAGE 2" << endl << "STAGE 3" << endl;
		cout << "번호를 입력하여 스테이지를 선택하세요." << endl << "(0 - 종료, 9 - 설명) : ";
		cin >> stage;
		if (stage == 9) {
			system("cls");
			cout << "\t조작" << endl << endl << "Space, ↑ - 점프" << endl << "↓ - 웅크리기" << endl << endl << endl;
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
		else if (stage == 0) { break; }
		else if (stage >= 10) { stageClear[stage - 10] = true; continue; }
		else if (stage > 3 || stage < 0) { continue; }
		else if (stage != 1 && stageClear[stage - 2] == false) {
			cout << "이전 스테이지를 먼저 클리어해주세요." << endl;
			cout << "1초 후에 스테이지 선택 화면으로 되돌아갑니다." << endl;
			Sleep(1000);
			continue;
		}

		SetStage(stage, stageMap);
		CreateItem(stageMap);
		SetNewGame(&tPlayer);
		while (true)
		{
			system("cls");

			if (CheckStageEnd(&tPlayer))
			{
				stageClear[stage - 1] = true;
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