#include "Stage.h"

random_device rd;
//mt19937 end(rd());
minstd_rand eng(rd());
uniform_int_distribution<int> uid(0, 99);

void SetNewGame(PPLAYER player)
{
	player->hp = 3;
	player->tPos.x = 0;
	player->tPos.y = 4;
}

void SetStage(int stage, char map[HEIGHT][WEIGHT])
{
	switch (stage)
	{
	case 1:
		speed = 150;
		endPos.x = 99;
		strcpy_s(map[0], "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002");
		strcpy_s(map[1], "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002");
		strcpy_s(map[2], "0000000000000000000000000000000000000000000000000000000000000000000000044000000000000000000000000002");
		strcpy_s(map[3], "0000000000000000000000000000000000000000000000000000000000000000000000044000000000000000000000000002");
		strcpy_s(map[4], "0000000000000000000000000303000000003000000003000000000000000000000000000000000000030000000000000002");
		strcpy_s(map[5], "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111");
		break;
	case 2:
		speed = 100;
		endPos.x = 499;
		strcpy_s(map[0], "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002");
		strcpy_s(map[1], "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002");
		strcpy_s(map[2], "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002");
		strcpy_s(map[3], "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002");
		strcpy_s(map[4], "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002");
		strcpy_s(map[5], "11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111");
		break;
	case 3:
		speed = 50;
		endPos.x = 799;

		break;
	default:
		break;
	}
}

void SetPlayerDown(PPLAYER player)
{
	if (player->isDown) {
		player->isDown = false;
	}
}

void SetPlayerJump(PPLAYER player)
{
	if (player->isJump && jumpPos.x + 3 == player->tPos.x) {
		player->isJump = false;
		++player->tPos.y;
	}
}

void SetPlayerItem(PPLAYER player)
{
	if (player->isStar && starPos.x + 10 == player->tPos.x) {
		player->isStar = false;
	}
}

void PrintStage(char map[HEIGHT][WEIGHT], PPLAYER player)
{

	//Hp 출력
	cout << "Hp : ";
	setColor(12, 7);
	for (int i = 0; i < player->hp; i++)
	{
		cout << "♥ ";
	}
	//cout << "\t Speed:" << speed;
	cout << endl;
	setColor(0, 7);

	//스테이지 출력
	int printX = player->tPos.x + 15;
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = player->tPos.x; j < printX; j++)
		{
			if (player->tPos.x == j && player->tPos.y == i + 1 && !player->isDown) {
				if (player->isStar) {
					setColor(6, 7);
					cout << "▲";
					setColor(0, 7);
					continue;
				}
				cout << "▲";
			}
			else if (player->tPos.x == j && player->tPos.y == i)
			{
				if (player->isStar) {
					setColor(6, 7);
					if (player->isDown) {
						cout << "▲";
					}
					else
					{
						cout << "▼";
					}
					setColor(0, 7);
					continue;
				}
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
			else if (map[i][j] == '5') {
				setColor(6, 7);
				cout << "★";
				setColor(0, 7);
			}
			else if (map[i][j] == '6') {
				setColor(4, 7);
				cout << "♬";
				setColor(0, 7);
			}
			else if (map[i][j] == '7') {
				setColor(1, 7);
				cout << "♬";
				setColor(0, 7);
			}
			else if (map[i][j] == '8') {
				setColor(12, 7);
				cout << "♡";
				setColor(0, 7);
			}
		}
		cout << endl;
	}
	cout << "점프 : ↑, 웅크리기 : ↓/Space" << endl;
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
	PlaySound(MAKEINTRESOURCE(IDR_WAVE1), NULL, SND_RESOURCE);
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
		if (player->isStar == false) {
			PlaySound(MAKEINTRESOURCE(IDR_WAVE2), NULL, SND_RESOURCE);
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
	}
	else if (map[y][x] != '0' && map[y][x] != '2') {
		GetItem(map[y][x], player);
	}
	else if (map[y - 1][x] != '0' && map[y - 1][x] != '2' && !player->isDown)
	{
		GetItem(map[y - 1][x], player);
	}
	++player->tPos.x;
}

void CreateItem(char map[HEIGHT][WEIGHT])
{
	for (int i = 2; i < 5; i++)
	{
		for (int j = 0; j < endPos.x; j++)
		{
			if (map[i][j] == '0') {
				if (uid(eng) < 3) {
					int random = uid(eng);
					if (random <= 9) {
						map[i][j] = '5';
					}
					else if (random <= 19) {
						map[i][j] = '6';
					}
					else if (random <= 29) {
						map[i][j] = '7';
					}
					else if (random <= 34) {
						map[i][j] = '8';
					}
				}
			}
		}
	}
}

void GetItem(char item, PPLAYER player)
{
	int temp = speed / 2;
	switch (item)
	{
	case '5':
		player->isStar = true;
		starPos.x = player->tPos.x;
		break;
	case '6':
		speed -= temp;
		break;
	case '7':
		speed += temp;
		break;
	case '8':
		++player->hp;
		break;
	}

}


bool CheckHp(PPLAYER player)
{
	if (player->hp <= 0) {
		return true;
	}
	return false;
}


bool CheckEnd(PPLAYER player)
{
	if (endPos.x == player->tPos.x) {
		return true;
	}
	return false;
}