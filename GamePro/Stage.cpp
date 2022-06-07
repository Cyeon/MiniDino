#include "Stage.h"
#include"Console.h"
using namespace std;

void SetStage(int stage, char map[HEIGHT][WEIGHT])
{
	switch (stage)
	{
	case 1:
		speed = 150;
		endPos.x = 99;
		strcpy_s(map[0], "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002");
		strcpy_s(map[1], "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002");
		strcpy_s(map[2], "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002");
		strcpy_s(map[3], "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002");
		strcpy_s(map[4], "0000000000000000000001000000000000000000000000000000000000000000000000000000000000000000000000000002");
		strcpy_s(map[5], "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111");
	case 2:

	case 3:
	default:
		break;
	}
}

void SetPlayer(PPLAYER player)
{
	if (player->isDown) {
		player->isDown = false;
	}
	if (player->isJump) {

	}
}

void PrintStage(char map[HEIGHT][WEIGHT], PPLAYER player)
{
	int printX = player->tPos.x + 15;
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = player->tPos.x; j < printX; j++)
		{
			if (player->tPos.x == j && player->tPos.y == i + 1) {
				if (player->isDown) {
					cout << "  ";
				}
				else
				{
					cout << "▲";
				}
			}
			else if (player->tPos.x == j && player->tPos.y == i)
			{
				if (player->isDown) {
					cout << "▲";
				}
				else
				{
					cout << "▼";
				}
			}
			else if (map[i][j] == '0')
			{
				cout << "  ";
			}
			else if (map[i][j] == '1')
			{
				cout << "■";
			}
			else if (map[i][j] == '2')
			{
				cout << "□";
			}

		}
		cout << endl;
	}
	cout << "점프 : ↑, 웅크리기 : ↓" << endl;
	cout << "Q, q : 스테이지 선택 화면" << endl;
}

void MovePlayer(char map[HEIGHT][WEIGHT], PPLAYER player)
{
	if ((GetAsyncKeyState(VK_UP) & 0X8000) || (GetAsyncKeyState(VK_SPACE) & 0X8000)) {
		MoveJump(map, player);
	}
	if (GetAsyncKeyState(VK_DOWN) & 0X8000) {
		MoveDown(map, player);
	}
}

void MoveJump(char map[HEIGHT][WEIGHT], PPLAYER player)
{
	if (player->isJump || player->isDown) { return; }
	player->isJump = true;
	--player->tPos.y;
}

void MoveDown(char map[HEIGHT][WEIGHT], PPLAYER player)
{
	if (player->isJump || player->isDown) { return; }
	player->isDown = true;
}

void SetNewGame(PPLAYER player)
{
	player->tPos.x = 0;
	player->tPos.y = 4;
}

bool CheckEnd(PPLAYER player)
{
	if (endPos.x == player->tPos.x) {
		return true;
	}
	return false;
}

