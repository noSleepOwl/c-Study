#include "pch.h"
#include "SnackConsole.h"
#include"console_tools.h"

console_n::SnackConsole::SnackConsole(int width, int height) :width(width), height(height)
{
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	initConsole();
	
}

void console_n::SnackConsole::initConsole() {
	//��ȡ����̨��Ϣ
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	info.srWindow.Right =width-1;
	info.srWindow.Bottom = height-1;
	// ���ÿ���̨�Ŀ�Ⱥ͸߶�
	SetConsoleWindowInfo(handle, true, &info.srWindow);
	// ������Ļ������
	COORD ar = { width,height };
	SetConsoleScreenBufferSize(handle, ar);
}

void console_n::SnackConsole::fillContent(char f_char, int fillNumber, int Attributes)
{
	CHAR_INFO CharInfo;
	CharInfo.Attributes = Attributes;//����ɫΪ��ɫ
	CharInfo.Char.AsciiChar = f_char;//�ո��ַ� 
	// �������
	CHAR_INFO *charInfoAarray = new CHAR_INFO[fillNumber];
	for (int i = 0; i < fillNumber; i++)
	{
		charInfoAarray[i] = CharInfo;
	}

	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	// ��ȡ������ԭʼ��С
	COORD dwSize = info.dwSize;
	//��ʾ���Ļ�����: ��С��һ������
	SMALL_RECT rect = { 0, 0, width	, height };
	// ���
	COORD start = {0,0};
	//����
	WriteConsoleOutput(handle, charInfoAarray, dwSize, start, &rect);
	delete[] charInfoAarray; // ���ն�̬����
}
void console_n::SnackConsole::fillContent(char f_char, COORD start, COORD end) {
	CHAR_INFO CharInfo;
	CharInfo.Attributes = BACKGROUND_GREEN;//����ɫΪ��ɫ
	CharInfo.Char.AsciiChar = f_char;//�ո��ַ�
	// �������ַ�����ķ�ʽ���ԡ���������һЩ�����������
	int fillNumber =10000;
	// �������
	CHAR_INFO *charInfoAarray = new CHAR_INFO[fillNumber];
	for (int i = 0; i < fillNumber; i++)
	{
		charInfoAarray[i] = CharInfo;
	}

	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	// ��ȡ������ԭʼ��С
	COORD dwSize = info.dwSize;
	//��ʾ���Ļ�����: ��С��һ������
	SMALL_RECT rect = { start.X, start.Y, end.X	, end.Y};

	//����
	WriteConsoleOutput(handle, charInfoAarray, dwSize, start, &rect);
	delete[] charInfoAarray; // ���ն�̬����
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
	// ?? ��ʼ��λ�� ���ͽ�����λ����Ҫ��main ��ʼ
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
	// ?? ��ʼ��λ�� ���ͽ�����λ����Ҫ��main ��ʼ
	COORD start = { info.start.X ,info.end.Y+2 };
	COORD end = { width-2,height-2 };

	msg.start = start;
	msg.end = end;
	fillContent(' ', start, end);
}
