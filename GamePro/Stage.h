#pragma once
	const int HEIGHT = 5;
	const int WEIGHT = 100;
	typedef struct _pos {
		int x;
		int y;
	}POS, * PPOS;

	typedef struct _player {
		_pos tPos;
		bool isJump = false;
		bool isDown = false;
		bool isDead = false;
	}PLAYER, * PPLAYER;

	void SetStage(int stage,char map[HEIGHT][WEIGHT]);
	void PrintStage(char map[HEIGHT][WEIGHT],PPLAYER player,PPOS playerPos);
	void MoveJump  (char map[HEIGHT][WEIGHT],PPLAYER player,PPOS playerPos );
	void MoveDown  (char map[HEIGHT][WEIGHT],PPLAYER player,PPOS playerPos );