#include <io.h>
#include <fcntl.h>
#include"Console.h"
#include "Stage.h"
using namespace std;
char stageMap[HEIGHT][WEIGHT];
enum STAGE {
	STAGE_1 = 1,
	STAGE_2,
	STAGE_3
};
int main() {
	PLAYER tPlayer;
	tPlayer.tPos.x = 0;
	tPlayer.tPos.y = 4;
	int stage;
	cout << "Ÿ��Ʋ ����" << endl;
	cout << "Press Any Key To Start" << endl;
	_getch();
	system("cls");
	cout << "STAGE 1" << endl << "STAGE 2" << endl << "STAGE 3" << endl;
	cout << "��ȣ�� �Է��Ͽ� ���������� �����ϼ��� :";
	cin >> stage;
	SetStage(stage, stageMap);
	while (true)
	{
		system("cls");
		PrintStage(stageMap, &tPlayer);
		char cinput = GetKeyDown();
		if (cinput == 'q' || cinput == 'Q') {
			break;
		}
		MovePlayer(stageMap, &tPlayer);
		++tPlayer.tPos.x;
		Sleep(60);
	}
}