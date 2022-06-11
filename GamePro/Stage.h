#pragma once
const int HEIGHT = 6;
const int WEIGHT = 200;
static int speed = 100;
typedef struct _pos {
	int x;
	int y;
}POS, * PPOS;

static POS endPos;
static POS jumpPos;

typedef struct _player {
	_pos tPos;
	int hp = 1;
	bool isJump = false;
	bool isDown = false;
	bool isDead = false;
}PLAYER, * PPLAYER;


void SetNewGame(PPLAYER player);
void SetStage(int stage, char map[HEIGHT][WEIGHT]);
void SetPlayer(PPLAYER player);
void PrintStage(char map[HEIGHT][WEIGHT], PPLAYER player);
void MovePlayer(PPLAYER player);
void MoveJump(PPLAYER player);
void MoveDown(PPLAYER player);
void MoveRight(char map[HEIGHT][WEIGHT], PPLAYER player);
void CheckHp(PPLAYER player);
void GameOver();
bool CheckEnd(PPLAYER player);
