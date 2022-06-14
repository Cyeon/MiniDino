#pragma once
#include"Console.h"
#include"resource.h"
#include <random>
using namespace std;

const int HEIGHT = 6;
const int WEIGHT = 1000;
static int speed = 100;
static int sleepTime = 300;
typedef struct _pos {
	int x;
	int y;
}POS, * PPOS;

static POS endPos;
static POS jumpPos;
static POS starPos;

typedef struct _player {
	_pos tPos;
	int hp = 3;
	bool isJump = false;
	bool isDown = false;
	bool isDead = false;
	bool isStar = false;
}PLAYER, * PPLAYER;


void SetNewGame(PPLAYER player);
void SetStage(int stage, char map[HEIGHT][WEIGHT]);
void SetPlayerDown(PPLAYER player);
void SetPlayerJump(PPLAYER player);
void SetPlayerItem(PPLAYER player);
void PrintStage(char map[HEIGHT][WEIGHT], PPLAYER player);
void MovePlayer(PPLAYER player);
void MoveJump(PPLAYER player);
void MoveDown(PPLAYER player);
void MoveRight(char map[HEIGHT][WEIGHT], PPLAYER player);
void CreateItem(char map[HEIGHT][WEIGHT]);
void GetItem(char item, PPLAYER player);
bool CheckHp(PPLAYER player);
bool CheckEnd(PPLAYER player);