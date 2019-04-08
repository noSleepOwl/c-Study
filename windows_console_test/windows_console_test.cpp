
#include "pch.h"
#include <iostream>
#include<Windows.h>
#include<wincon.h>
#include<string>
#include <conio.h>   // console I/O 控制 
#include <atlbase.h>
HANDLE hOut;
void ShadowWindowLine(const char *str); // 在具有阴影效果的窗口中显示一行字符，窗口为居中显示
void DrawBox(bool bSingle, SMALL_RECT rc); // 绘制边框
LPCWSTR char2lpcstr(char tar) {
	
	wchar_t wtext[1];
	mbstowcs(wtext, &tar, 1);//Plus null
	return wtext;

}
void main()
{
	
	hOut = GetStdHandle(STD_OUTPUT_HANDLE); // 获取标准输出设备句柄
	SetConsoleOutputCP(437); // 设置代码页
	ShadowWindowLine("Display a line of words, and center the window with shadow.");
	CloseHandle(hOut); // 关闭标准输出设备句柄
}

void ShadowWindowLine(const char* str)
{
	CONSOLE_SCREEN_BUFFER_INFO bInfo; // 窗口缓冲区信息
	GetConsoleScreenBufferInfo(hOut, &bInfo); // 获取窗口缓冲区信息
	// 计算显示窗口大小和位置
	int x1, y1, x2, y2, chNum = strlen(str);
	x1 = (bInfo.dwSize.X - chNum) / 2 - 2;
	y1 = bInfo.dwSize.Y / 2 - 2;
	x2 = x1 + chNum + 4;
	y2 = y1 + 5;
	WORD att1 = BACKGROUND_INTENSITY; // 阴影属性
	WORD att0 = FOREGROUND_RED |
							FOREGROUND_GREEN |
							FOREGROUND_BLUE |
							FOREGROUND_INTENSITY |
							BACKGROUND_RED | 
							BACKGROUND_BLUE; // 文本属性

	WORD attText = FOREGROUND_RED | FOREGROUND_INTENSITY; // 文本属性
	DWORD written;
	// 设置阴影
	COORD posShadow = { x1 + 1, y1 + 1 }, posText = { x1, y1 };
	for (int i = 0; i < 5; i++) {
		
		FillConsoleOutputAttribute(hOut, att1, chNum + 4, posShadow, &written);
		posShadow.Y++;
	}
	// 填充窗口背景
	for ( int i = 0; i < 5; i++) {
		FillConsoleOutputAttribute(hOut, att0, chNum + 4, posText, &written);
		posText.Y++;
	}
	// 写文本和边框
	posText.X = x1 + 2;
	posText.Y = y1 + 2;
	WriteConsoleOutputCharacter(hOut, (LPCWSTR)str, strlen(str), posText, &written);
	SMALL_RECT rc = { x1, y1, x2 - 1, y2 - 1 };
	DrawBox(true, rc);
	SetConsoleTextAttribute(hOut, bInfo.wAttributes); // 恢复原来的属性
}

void DrawBox(bool bSingle, SMALL_RECT rc)
{
	DWORD NumberOfCharsWritten;
	char chBox[6];
	if (bSingle) {
		chBox[0] = 'a'; // 左上角点
		chBox[1] = 'b'; // 右上角点
		chBox[2] = 'c'; // 左下角点
		chBox[3] = 'd'; // 右下角点
		chBox[4] = 'e'; // 水平
		chBox[5] = 'f'; // 坚直
	}
	else {
		chBox[0] = 'g'; // 左上角点
		chBox[1] = 'h'; // 右上角点
		chBox[2] = 'i'; // 左下角点
		chBox[3] = 'j'; // 右下角点
		chBox[4] = 'k'; // 水平
		chBox[5] = 'l'; // 坚直  测试提交信息...
	}
	COORD pos = { rc.Left, rc.Top };
	USES_CONVERSION;
	LPCSTR ch_0 = W2A(char2lpcstr(chBox[0]));
	LPCSTR ch_4 = W2A(char2lpcstr(chBox[4]));

	WriteConsoleOutputCharacterA(hOut, ch_0, 1, pos, &NumberOfCharsWritten);

	for (pos.X = rc.Left + 1; pos.X; pos.X -- ) {
		//std::cout << pos.X << std::endl;
		WriteConsoleOutputCharacterA(hOut, ch_4, 1, pos, &NumberOfCharsWritten);

	}

	pos.X = rc.Right;
	WriteConsoleOutputCharacter(hOut, char2lpcstr(chBox[1]), 1, pos, &NumberOfCharsWritten);

	for (pos.Y = rc.Top + 1; pos.Y; pos.Y--)
	{
		pos.X = rc.Left;
		WriteConsoleOutputCharacter(hOut, char2lpcstr(chBox[5]), 1, pos, &NumberOfCharsWritten);
		pos.X = rc.Right;
		WriteConsoleOutputCharacter(hOut, char2lpcstr(chBox[5]), 1, pos, &NumberOfCharsWritten);
	}
	pos.X = rc.Left; pos.Y = rc.Bottom;
	WriteConsoleOutputCharacter(hOut, char2lpcstr(chBox[2]), 1, pos, &NumberOfCharsWritten);

	for (pos.X = rc.Left + 1; pos.X; pos.X--)
		WriteConsoleOutputCharacter(hOut, char2lpcstr(chBox[4]), 1, pos, &NumberOfCharsWritten);

	pos.X = rc.Right;
	WriteConsoleOutputCharacter(hOut, char2lpcstr(chBox[3]), 1, pos, &NumberOfCharsWritten);
}
