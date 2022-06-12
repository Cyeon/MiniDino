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
		strcpy_s(map[3], "0000000000000040000000000000000000000000000000000000000000000000000000000000000000000000000000000002");
		strcpy_s(map[4], "0000000000000000000000000303000000001000000003000000000000000000000000000000000000000000000000000002");
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
	if (player->isJump && jumpPos.x + 3 == player->tPos.x) {
		player->isJump = false;
		++player->tPos.y;
	}
}

void PrintStage(char map[HEIGHT][WEIGHT], PPLAYER player)
{
	cout << "Hp : ";
	for (int i = 0; i < player->hp; i++)
	{
		cout << "♥ ";
	}
	cout << endl;

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
			else if (map[i][j] == '3')
			{
				cout << "△";
			}
			else if (map[i][j] == '4')
			{
				cout << "◁";
			}

		}
		cout << endl;
	}
	cout << "점프 : ↑, 웅크리기 : ↓" << endl;
	cout << "Q, q : 스테이지 선택 화면" << endl;
}

void MovePlayer(PPLAYER player)
{
	if ((GetAsyncKeyState(VK_UP) & 0X8000) || (GetAsyncKeyState(VK_SPACE) & 0X8000)) {
		MoveJump(player);
	}
	if (GetAsyncKeyState(VK_DOWN) & 0X8000) {
		MoveDown(player);
	}
}

void MoveJump(PPLAYER player)
{
	if (player->isJump || player->isDown) { return; }
	player->isJump = true;
	--player->tPos.y;
	jumpPos = player->tPos;
}

void MoveDown(PPLAYER player)
{
	if (player->isJump || player->isDown) { return; }
	player->isDown = true;
}

void MoveRight(char map[HEIGHT][WEIGHT], PPLAYER player)
{
	int x = player->tPos.x + 1;
	int y = player->tPos.y;
	if (map[y][x] == '3' || map[y - 1][x] == '3' || (map[y - 1][x] == '4' && !player->isDown)) {
		--player->hp;
		if (!CheckHp(player)) {
			for (int i = 0; i < 3; i++)
			{
				system("cls");
				Sleep(sleepTime);
				PrintStage(map, player);
				Sleep(sleepTime);
			}
		}
	}
	++player->tPos.x;
}

bool CheckHp(PPLAYER player)
{
	if (player->hp <= 0) {
		return true;
	}
	return false;
}

void SetNewGame(PPLAYER player)
{
	player->hp = 3;
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