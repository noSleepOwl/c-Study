#pragma once
#include <Windows.h>
#include<iostream>
#include"console_tools.h"

// 对该类重新设计
// 此类负责控制界面的生成
// 其为一个容器，绘制对应部分的信息 
namespace console_n {
	using std::cout;
	using std::endl;

	// 表示 区域信息的结构
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
		// 主要 
		area mainContent = {
			3,5
		};
		// level speed 展示的地方
		area info = {
			2,2
		};
		// 提示信息区域
		area msg = {
			2,3
		};
		void drawBackground();
		void drawMainContent();
		void drawInfo();
		void drawMsg();
	};


}

