#pragma once
#include <Windows.h>
#include<iostream>
#include"console_tools.h"
namespace console_n {
	// 控制台类
	// 控制台信息的实现 1. 绘制当前控制窗口的边界，2.保存窗口的信息，3.清空窗口信息，4。输出窗口信息或者文字
	using std::cout;
	using std::endl;
	class SnackConsole
	{
	public:
		
		// 根据宽度和高度来初始化容器
		// borderSize 边框厚度，默认的是1
		// 如果为子容器，该宽度和高度为比例
		SnackConsole(int width,int height,int borderSize = 1);
		~SnackConsole();

		// 获取控制台句柄 如果存在上级容器，则取上级容器的，如果不存在则取自身的新的；
		HANDLE getHandel() const;

		// 设置父级容器
		void setParent(SnackConsole *parent);


		// 判断是否有父级容器
		bool  haveParent() const;

		// 获取空闲位置信息 子集容器占用的地方，并且大于 边框的字符数量 子集容器按照先上后下，先左后右的顺序绘制
		COORD getNextStart() const;
		void setNextStart(short x, short y);

		// 绘制
		void draw();
	private :
		const int width;
		const int height;
		// 起点 如果父级为空，起点为0，0 ，否则查询父级空闲位置中+边框宽度后进行设置
		COORD start; 
		//终点 同start 
		COORD end; 
		// 指定下一次子集的起点位置，不包含border；
		COORD nextStart;
		// 父级容器
		const SnackConsole *parent=NULL; 
		
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		// 边框厚度
		int borderSize ; 
		// 宽度和高度的比例基准，在计算子容器的时候使用
		int widthScale = 5;
		int heightScale = 5;

		void computeStartPoint();
		void computeEndPoint();
		void fillContent(char f_char,int fillNumber,int attr = BACKGROUND_RED);
	};


}

