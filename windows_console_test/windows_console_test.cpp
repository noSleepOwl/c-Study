
#include "pch.h"
#include<iostream>
#include <Windows.h>
#include<conio.h>
using std::cout;
using std::endl;

HANDLE hout;

// 清除函数
void cle(COORD prPos);
// 输出
void print(COORD prPos);
// 移动
void move(COORD *prPos, int key);




void main()
{
	hout = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD cord = {0,1};
	print(cord);
	while (1)
	{
		if (_kbhit()) {
			cle(cord);
			move(&cord, _getch());
			print(cord);
		}
	}

}

void cle(COORD prPos)
{
	//SetConsoleCursorPosition(hout, prPos);
	COORD rd = { 0,0 };
	DWORD lp = 0;
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(hout, &info);
	// 最后一个参数现在不可以填写NULL 需要传入 DWORD 的引用(虽然参数类型是LPDWORD的...)
	FillConsoleOutputCharacter(hout, ' ', info.dwSize.X *info.dwSize.Y, rd, &lp);
}

void print(COORD prPos)
{
	SetConsoleCursorPosition(hout, prPos);
	cout << "hello world";
}

void move(COORD * prPos, int key)
{
	switch (key)
	{
	case 72:  prPos->Y--;		break;
	case 75:  prPos->X--;		break;
	case 77:  prPos->X++;		break;
	case 80:  prPos->Y++;		break;
	default:		break;
	}
}
