#include <io.h>
#include <fcntl.h>
#include"Console.h"
#include "Stage.h"
using namespace std;
enum STAGE {
	STAGE_1=1,
	STAGE_2,
	STAGE_3
};
int main() {
	int stage;
	cout << "���沾��" << endl;
	cout << "Press Any Key To Start" << endl;
	_getch();
	system("cls");
	cout << "STAGE 1" << endl << "STAGE 2" << endl << "STAGE 3" << endl;
	cout << "��ȣ�� �Է��Ͽ� ���������� �����ϼ��� :";
	cin >> stage;
	switch (stage)
	{
	case STAGE_1:
	case STAGE_2:
	case STAGE_3:
	default:
		break;
	}
}	