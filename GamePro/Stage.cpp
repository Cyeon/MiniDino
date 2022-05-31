#include "Stage.h"
#include"Console.h"

void SetStage(int stage, char map[HEIGHT][WEIGHT])
{
	switch (stage)
	{
	case 1:

	case 2:

	case 3:
	default:
		break;
	}
}

void PrintStage(char map[HEIGHT][WEIGHT], PPLAYER player, PPOS playerPos)
{
	//플레이어 포스 기준으로 출력 범위 잡기 
	//점프를 해도 위에 스테이지가 있지는 않으니까 y는 범위 고정시키고 x만 범위 잡아주기 
	//범위를 기준으로 출력 
		// 그럼 내가 원래 미로 코드와 다르게 짜야할 부분은? 
		// 범위 만들기, 그거 기준으로 for문 설정하기 		
	//숙이기 기능을 위해서 플레이어는 두 칸으로 잡자 
	// 일단 기본 점프로 올라가는 칸은 한 칸 
		//1단 점프와 2단 점프 키를 구분해서 넣어도 좋을듯 
}

void MoveJump(char map[HEIGHT][WEIGHT], PPLAYER player, PPOS playerPos)
{
	player->isJump = true;
}

void MoveDown(char map[HEIGHT][WEIGHT], PPLAYER player, PPOS playerPos)
{
	player->isDown = true;
}
