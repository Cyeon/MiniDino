#pragma once
#include"Console.h"
#include"resource.h"
#include <random>
using namespace std;

typedef struct _pos {
	int x;
	int y;
}POS, * PPOS;

typedef struct _player {
	_pos tPos;
	int hp = 3;
	bool isJump = false;
	bool isDown = false;
	bool isDead = false;
	bool isStar = false;
}PLAYER, * PPLAYER;

//BGM
static MCI_OPEN_PARMS OpenBgm;
static MCI_PLAY_PARMS PlayBgm;

static MCI_OPEN_PARMS OpenJumpEffect;
static MCI_PLAY_PARMS PlayJumpEffect;

static UINT dwID1;
static UINT dwID2; 

const int HEIGHT = 6;
const int WEIGHT = 1000;

static int speed = 100;
static int sleepTime = 300;
static POS endPos;
static POS jumpPos;
static POS starPos;

void PlayingBgm();
void PlayingJumpEffect();
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