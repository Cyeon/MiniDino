#include "Stage.h"
#include"Console.h"
using namespace std;

void SetStage(int stage, char map[HEIGHT][WEIGHT])
{
	switch (stage)
	{
	case 1:
		strcpy_s(map[0], "00000000000000000000000000000000000000000000000000");
		strcpy_s(map[1], "00000000000000000000000000000000000000000000000000");
		strcpy_s(map[2], "00000000000000000000000000000000000000000000000000");
		strcpy_s(map[3], "00000000000000000000000000000000000000000000000000");
		strcpy_s(map[4], "00000000000000000000010000000000000000000000000000");
		strcpy_s(map[5], "11111111111111111111111111111111111111111111111111");
	case 2:

	case 3:
	default:
		break;
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
				if (player->isDown) { continue; }
				cout << "▲";
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
		}
		cout << endl;
	}
	cout << "점프 : ↑, 웅크리기 : ↓" << endl;
	cout << "Q, q : 종료" << endl;
}

void MovePlayer(char map[HEIGHT][WEIGHT], PPLAYER player)
{
	if (GetAsyncKeyState(VK_UP) & 0X8000) {
		MoveJump(map, player);
	}
	if (GetAsyncKeyState(VK_DOWN) & 0X8000) {
		MoveDown(map, player);
	}
}

void MoveJump(char map[HEIGHT][WEIGHT], PPLAYER player)
{
	if (player->isJump||player->isDown) { return; }
	player->isJump = true;
	--player->tPos.y;
}

void MoveDown(char map[HEIGHT][WEIGHT], PPLAYER player)
{
	if (player->isJump || player->isDown) { return; }
	player->isDown = true;
}