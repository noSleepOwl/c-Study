#pragma once
#include <Windows.h>
#include<iostream>
#include"console_tools.h"

// �Ը����������
// ���ฺ����ƽ��������
// ��Ϊһ�����������ƶ�Ӧ���ֵ���Ϣ 
namespace console_n {
	using std::cout;
	using std::endl;

	// ��ʾ ������Ϣ�Ľṹ
	struct area
	{
		int width;
		int height;
		COORD start;
		COORD end;
	};

	class SnackConsole
	{
	public:
		SnackConsole(int width, int height);
		void initConsole();
		void fillContent(char f_char, int fillNumber, int Attributes);
		void fillContent(char f_char, COORD start, COORD end);
		void draw();
	private :
		int width;
		int height;
		int widthScale = 5;
		int heightScale = 5;
		HANDLE handle;
		// ��Ҫ 
		area mainContent = {
			3,5
		};
		// level speed չʾ�ĵط�
		area info = {
			2,2
		};
		// ��ʾ��Ϣ����
		area msg = {
			2,3
		};
		void drawBackground();
		void drawMainContent();
		void drawInfo();
		void drawMsg();
	};


}

