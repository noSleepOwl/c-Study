#include "pch.h"
#include "SnackConsole.h"
#include"console_tools.h"

console_n::SnackConsole::SnackConsole(int width, int height, int borderSize) :width(width), height(height),borderSize(borderSize)
{
	
}

console_n::SnackConsole::~SnackConsole()
{
}

HANDLE console_n::SnackConsole::getHandel() const
{
	if (haveParent()) {
		return parent->getHandel();
	}
	else {
		return handle;
	}
	
}

void console_n::SnackConsole::setParent(SnackConsole * parent)
{
	this->parent = parent;
}



void console_n::SnackConsole::computeStartPoint()
{
	if (haveParent()) {
		start = parent->getNextStart();
		start.X++;
		start.Y++;
		
	}
	else
	{
		start.X = 0;
		start.Y = 0;
		
	}
}

void console_n::SnackConsole::computeEndPoint()
{
	
	if (haveParent()) {
		end.X =  parent->width / widthScale * width;
		end.Y = parent->height / heightScale * height;
		end.X-=2;
		end.Y-=2;
	}
	else
	{
		end.X = width;
		end.Y = height;
	}
}

void console_n::SnackConsole::fillContent(char f_char,int fillNumber,int Attributes )
{
	CHAR_INFO CharInfo;
	CharInfo.Attributes = Attributes;//����ɫΪ��ɫ
	CharInfo.Char.AsciiChar = f_char;//�ո��ַ� 
	// �������
	CHAR_INFO *charInfoAarray = new CHAR_INFO[fillNumber];
	for ( int i = 0; i < fillNumber; i++)
	{
			charInfoAarray[i] = CharInfo;
	}

	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);

	COORD dwSize = info.dwSize;
	SMALL_RECT rect = { start.X, start.Y, end.X	, end.Y };//��ʾ���Ļ�����: ��С��һ������
	WriteConsoleOutput(handle, charInfoAarray, dwSize, start, &rect);
	delete[] charInfoAarray; // ���ն�̬����
}



bool console_n::SnackConsole::haveParent() const
{
	return parent ? true : false;
}

COORD console_n::SnackConsole::getNextStart() const
{
	return nextStart;
}

void console_n::SnackConsole::setNextStart(short x, short y) 
{
	nextStart.X = x;	
	nextStart.Y = y;
}

COORD console_n::SnackConsole::getStart() const
{
	return start;
}

COORD console_n::SnackConsole::getEnd() const
{
	return end;
}





void console_n::SnackConsole::draw()
{
	computeStartPoint();
	computeEndPoint();
	
	if (!haveParent()) {
		setNextStart(start.X, start.Y);
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

		
		//SMALL_RECT rc = { 0,0, end.X - 1,end.Y-1}; // ���ô���λ�úʹ�С
		
		CONSOLE_SCREEN_BUFFER_INFO info;
		GetConsoleScreenBufferInfo(handle, &info);
		info.srWindow.Right = (end.X - 1);
		info.srWindow.Bottom = (end.Y - 1);
		
	

		SetConsoleWindowInfo(handle, true, &info.srWindow);
		SetConsoleScreenBufferSize(handle, end);
		//cout << info << endl;
		fillContent('#', (end.X * end.Y));
	}
	else
	{
		//setNextStart(end.X, start.Y);
		fillContent(' ', (end.X * end.Y), 0xfa);
	}
}
