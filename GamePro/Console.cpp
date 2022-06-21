#include "Console.h"
using namespace std;
void gotoxy(int x, int y) {
	HANDLE hOut;
	COORD Cur;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(hOut, Cur);
}
void setColor(int color, int bgColor) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgColor << 4) | color);
}

int GetKeyDown()
{
	if (_kbhit() != 0)
	{
		return _getch();
	}
	else
	{
		return 0;
	}
}

void CursorHide()
{
	CONSOLE_CURSOR_INFO curInfo;
	curInfo.bVisible = false;
	curInfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}
