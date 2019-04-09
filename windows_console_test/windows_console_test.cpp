
#include "pch.h"
#include<iostream>
#include <Windows.h>
#include<conio.h>
#include"SnackConsole.h"
#include"console_tools.h"
using std::cout;
using std::endl;

const int WIDTH = 60;
const int HEIGHT = 30;


int main()
{
	using console_n::SnackConsole;
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);//获取控制台输入句柄
	// 主界面填充
	SnackConsole snackConsole(WIDTH,HEIGHT);
	snackConsole.draw();
	// 主窗口绘制
	/*SnackConsole mainContent(3, 5);
	mainContent.setParent(&snackConsole);
	mainContent.draw();*/
	// 得分窗口
	snackConsole.setNextStart(20,5);
	SnackConsole scoreContent(2, 2);
	scoreContent.setParent(&snackConsole);
	scoreContent.draw();

	while (true)
	{
		//cout << "12" << endl;
	}

	//int i = 0, j = 0;
	//CHAR_INFO CharInfo;
	//CharInfo.Attributes = BACKGROUND_RED;//背景色为红色
	//CharInfo.Char.UnicodeChar = '-';//空格字符 
	//CONSOLE_SCREEN_BUFFER_INFO info;
	//GetConsoleScreenBufferInfo(hConsoleOutput, &info);

	//short x = info.dwSize.X;
	//short y = info.dwSize.Y;

	//CHAR_INFO *charInfoAarray = new CHAR_INFO[x*y];

	//for (i = 0; i < (x*y); i++)
	//{
	//		charInfoAarray[i] = CharInfo;

	//}
	////cout << info.dwSize.X << info.dwSize.Y << endl;
	////COORD dwBufferSize = { 80,25 };//固定值(控制台窗口固定的属性值)
	//COORD dwBufferCoord = { 0, 0 };//缓冲区左上角的起始位置
	//SMALL_RECT rect = { 0, 0, x, y};//显示多大的缓冲区: 大小是一个矩形
	//WriteConsoleOutput(hConsoleOutput, charInfoAarray, info.dwSize, dwBufferCoord, &rect);
	//rect = {1,1,x-1,y-1};
	//WriteConsoleOutput(hConsoleOutput, charInfoAarray, info.dwSize, dwBufferCoord, &rect);

	//delete[] charInfoAarray; // 回收动态数组
	//getchar();
	return 0;
}


