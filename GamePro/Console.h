#pragma once
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <time.h>
#include <tchar.h>
#include <mmsystem.h>
#include <Digitalv.h>
#include"resource.h"
#include <random>
void gotoxy(int x, int y);
void setColor(int color, int bgColor);
int GetKeyDown();
void CursorHide();