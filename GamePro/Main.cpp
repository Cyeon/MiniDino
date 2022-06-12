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

	int stage;
	cout << "Ÿ��Ʋ ����" << endl;
	cout << "Press Any Key To Start" << endl;
	_getch();
	while (true) {
		system("cls");
		cout << "STAGE 1" << endl << "STAGE 2" << endl << "STAGE 3" << endl;
		cout << "��ȣ�� �Է��Ͽ� ���������� �����ϼ��� (0 - ����):";
		cin >> stage;
		if (stage == 0) { break; }
		SetNewGame(&tPlayer);
		SetStage(stage, stageMap);
		while (true)
		{
			system("cls");

			if (CheckEnd(&tPlayer))
			{
				cout << "STAGE " << stage << " CLEAR!" << endl;
				cout << "3�� �Ŀ� �������� ���� ȭ������ �ǵ��ư��ϴ�." << endl;
				cout << "3... "; Sleep(1000);
				cout << "2... "; Sleep(1000);
				cout << "1... "; Sleep(1000);
				break;
			}
			else if (CheckHp(&tPlayer)) {
				cout << "GAME OVER!" << endl;
				cout << "3�� �Ŀ� �������� ���� ȭ������ �ǵ��ư��ϴ�." << endl;
				cout << "3... "; Sleep(1000);
				cout << "2... "; Sleep(1000);
				cout << "1... "; Sleep(1000);
				break;
			}

			PrintStage(stageMap, &tPlayer);

			SetPlayer(&tPlayer);

			char cinput = GetKeyDown();

			if (cinput == 'q' || cinput == 'Q') {
				break;
			}

			MovePlayer(&tPlayer);
			MoveRight(stageMap, &tPlayer);
			Sleep(speed);
		}
	}
}