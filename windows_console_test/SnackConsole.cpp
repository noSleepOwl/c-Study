#include "pch.h"
#include "SnackConsole.h"
#include"console_tools.h"

console_n::SnackConsole::SnackConsole(int width, int height) :width(width), height(height)
{
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	initConsole();
	
}

void console_n::SnackConsole::initConsole() {
	//获取控制台信息
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	info.srWindow.Right =width-1;
	info.srWindow.Bottom = height-1;
	// 设置控制台的宽度和高度
	SetConsoleWindowInfo(handle, true, &info.srWindow);
	// 设置屏幕缓冲区
	COORD ar = { width,height };
	SetConsoleScreenBufferSize(handle, ar);
}

void console_n::SnackConsole::fillContent(char f_char, int fillNumber, int Attributes)
{
	CHAR_INFO CharInfo;
	CharInfo.Attributes = Attributes;//背景色为红色
	CharInfo.Char.AsciiChar = f_char;//空格字符 
	// 填充数量
	CHAR_INFO *charInfoAarray = new CHAR_INFO[fillNumber];
	for (int i = 0; i < fillNumber; i++)
	{
		charInfoAarray[i] = CharInfo;
	}

	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	// 获取缓冲区原始大小
	COORD dwSize = info.dwSize;
	//显示多大的缓冲区: 大小是一个矩形
	SMALL_RECT rect = { 0, 0, width	, height };
	// 起点
	COORD start = {0,0};
	//绘制
	WriteConsoleOutput(handle, charInfoAarray, dwSize, start, &rect);
	delete[] charInfoAarray; // 回收动态数组
}
void console_n::SnackConsole::fillContent(char f_char, COORD start, COORD end) {
	CHAR_INFO CharInfo;
	CharInfo.Attributes = BACKGROUND_GREEN;//背景色为红色
	CharInfo.Char.AsciiChar = f_char;//空格字符
	// 好像是字符计算的方式不对。。。少了一些将会出现乱码
	int fillNumber =10000;
	// 填充数量
	CHAR_INFO *charInfoAarray = new CHAR_INFO[fillNumber];
	for (int i = 0; i < fillNumber; i++)
	{
		charInfoAarray[i] = CharInfo;
	}

	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	// 获取缓冲区原始大小
	COORD dwSize = info.dwSize;
	//显示多大的缓冲区: 大小是一个矩形
	SMALL_RECT rect = { start.X, start.Y, end.X	, end.Y};

	//绘制
	WriteConsoleOutput(handle, charInfoAarray, dwSize, start, &rect);
	delete[] charInfoAarray; // 回收动态数组
}
void console_n::SnackConsole::draw()
{
	drawBackground();
	drawMainContent();
	drawInfo();
	drawMsg();
}

void console_n::SnackConsole::drawBackground()
{
	fillContent('*', width*height, BACKGROUND_BLUE);
}

void console_n::SnackConsole::drawMainContent()
{
	int mainH = 	height / heightScale * mainContent.height;
	int mainW = width / widthScale * mainContent.width;
	COORD start = { 1,1 };
	COORD end = { mainW-1,mainH -2};

	mainContent.start = start;
	mainContent.end = end;

	fillContent(' ', start, end);
}

void console_n::SnackConsole::drawInfo()
{
	int mainH = height / heightScale * info.height;
	int mainW = width / widthScale * info.width;
	// ?? 开始的位置 ，和结束的位置需要从main 开始
	COORD start = { mainContent.end.X+2,1 };
	COORD end = { width- 2,mainH - 1 };

	info.start = start;
	info.end = end;
	fillContent(' ', start, end);
}

void console_n::SnackConsole::drawMsg()
{
	int mainH = height / heightScale * msg.height;
	int mainW = width / widthScale * msg.width;
	// ?? 开始的位置 ，和结束的位置需要从main 开始
	COORD start = { info.start.X ,info.end.Y+2 };
	COORD end = { width-2,height-2 };

	msg.start = start;
	msg.end = end;
	fillContent(' ', start, end);
}
