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
	//�÷��̾� ���� �������� ��� ���� ��� 
	//������ �ص� ���� ���������� ������ �����ϱ� y�� ���� ������Ű�� x�� ���� ����ֱ� 
	//������ �������� ��� 
		// �׷� ���� ���� �̷� �ڵ�� �ٸ��� ¥���� �κ���? 
		// ���� �����, �װ� �������� for�� �����ϱ� 		
	//���̱� ����� ���ؼ� �÷��̾�� �� ĭ���� ���� 
	// �ϴ� �⺻ ������ �ö󰡴� ĭ�� �� ĭ 
		//1�� ������ 2�� ���� Ű�� �����ؼ� �־ ������ 
}

void MoveJump(char map[HEIGHT][WEIGHT], PPLAYER player, PPOS playerPos)
{
	player->isJump = true;
}

void MoveDown(char map[HEIGHT][WEIGHT], PPLAYER player, PPOS playerPos)
{
	player->isDown = true;
}
