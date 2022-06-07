#pragma once
const int HEIGHT = 6;
const int WEIGHT = 200;
static int speed = 100;
typedef struct _pos {
	int x;
	int y;
}POS, * PPOS;

static POS endPos;

typedef struct _player {
	_pos tPos;
	bool isJump = false;
	bool isDown = false;
	bool isDead = false;
}PLAYER, * PPLAYER;


void SetNewGame(PPLAYER player);
void SetStage(int stage, char map[HEIGHT][WEIGHT]);
void SetPlayer(PPLAYER player);
void PrintStage(char map[HEIGHT][WEIGHT], PPLAYER player);
void MovePlayer(char map[HEIGHT][WEIGHT], PPLAYER player);
void MoveJump(char map[HEIGHT][WEIGHT], PPLAYER player);
void MoveDown(char map[HEIGHT][WEIGHT], PPLAYER player);
bool CheckEnd(PPLAYER player);
