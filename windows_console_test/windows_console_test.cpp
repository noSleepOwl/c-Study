
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
//void print(COORD prPos,)
// 移动
void move(COORD *prPos, int key);




void main()
{
	
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);//获取控制台输入句柄

	int i = 0, j = 0;
	CHAR_INFO CharInfo;
	CharInfo.Attributes = BACKGROUND_RED;//背景色为红色
	CharInfo.Char.UnicodeChar = '-';//空格字符 
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &info);

	short x = info.dwSize.X;
	short y = info.dwSize.Y;

	CHAR_INFO *charInfoAarray = new CHAR_INFO[x*y];

	for (i = 0; i < (x*y); i++)
	{
			charInfoAarray[i] = CharInfo;

	}
	//cout << info.dwSize.X << info.dwSize.Y << endl;
	//COORD dwBufferSize = { 80,25 };//固定值(控制台窗口固定的属性值)
	COORD dwBufferCoord = { 0, 0 };//缓冲区左上角的起始位置
	SMALL_RECT rect = { 0, 0, x, y};//显示多大的缓冲区: 大小是一个矩形
	WriteConsoleOutput(hConsoleOutput, charInfoAarray, info.dwSize, dwBufferCoord, &rect);
	rect = {1,1,x-1,y-1};
	WriteConsoleOutput(hConsoleOutput, charInfoAarray, info.dwSize, dwBufferCoord, &rect);

	delete[] charInfoAarray; // 回收动态数组
	getchar();

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
	CHAR_INFO info;
	info.Attributes = BACKGROUND_BLUE;
	info.Char.AsciiChar = '-';
	
	CHAR_INFO infoArray[1];
	infoArray[0] = info;

	COORD dwBufferSize = { prPos.X+1,prPos.Y + 1 };//固定值(控制台窗口固定的属性值)
	//COORD dwBufferCoord = { 0, 0 };//缓冲区左上角的起始位置

	SMALL_RECT rect = { 0, 0, 79, 24 };//显示多大的缓冲区: 大小是一个矩形

	WriteConsoleOutput(hout, infoArray, prPos, dwBufferSize,&rect);
	//cout << "hello world";
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
