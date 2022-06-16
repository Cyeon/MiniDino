#include <io.h>
#include <fcntl.h>
#include<iomanip> 
#include"Console.h"
#include "Stage.h"
using namespace std;
char stageMap[HEIGHT][WEIGHT];
int main() {
	setColor(0, 7);
	system("cls");
	PLAYER tPlayer;
	int stage;
	cout << "Ÿ��Ʋ ����" << endl;
	cout << "Press Any Key To Start" << endl;
	_getch();
	while (true) {
		system("cls");
		cout << "STAGE 1" << endl << "STAGE 2" << endl << "STAGE 3" << endl;
		cout << "��ȣ�� �Է��Ͽ� ���������� �����ϼ��� (0 - ����, 9 - ����):";
		cin >> stage;
		if (stage == 0) { break; }
		else if (stage == 9) {
			system("cls");
			cout << "\t\t\t���� ����" << endl << endl;
			cout << "\t����" << endl << endl << "space, �� - ����" << endl << "�� - ��ũ����" << endl << endl << endl;
			cout << "\t������" << endl << endl;
			setColor(6, 7);
			cout << "��";
			setColor(0, 7);
			cout << " - ����" << endl;
			setColor(12, 7);
			cout << "��";
			setColor(0, 7);
			cout << " - HP ��" << endl;
			setColor(4, 7);
			cout << "��";
			setColor(0, 7);
			cout << "/";
			setColor(1, 7);
			cout << "��";
			setColor(0, 7);
			cout << " - ���ǵ� ��/�ٿ�" << endl << endl << endl;
			cout << "Ű�� ������ �������� ���� ȭ������ �ǵ��� ���ϴ�." << endl;
			_getch();
			continue;
		}
		SetStage(stage, stageMap);
		CreateItem(stageMap);
		SetNewGame(&tPlayer);
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

			SetPlayerJump(&tPlayer);
			SetPlayerItem(&tPlayer);
			PrintStage(stageMap, &tPlayer);
			SetPlayerDown(&tPlayer);
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