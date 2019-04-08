
#include "pch.h"
#include <iostream>
#include<Windows.h>
#include<string>
#include <conio.h>   // console I/O 控制 

using std::cout;
using std::endl;
using std::string;
LPWSTR *getTitle(void);

int main()
{
	HANDLE hOut;
	// 获取标准输出设备句柄
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hOut, &consoleInfo);


	LPWSTR* title = getTitle();
	

	cout << *title << endl;

	SetConsoleTitle(L"hello world console");

	title = getTitle();

	cout << *title << endl;

	return 0;
}

LPWSTR* getTitle(void)
{
	LPWSTR strTitle[255];
	// 获取窗口标题
	GetConsoleTitle(*strTitle, 255);
	return strTitle;
}
