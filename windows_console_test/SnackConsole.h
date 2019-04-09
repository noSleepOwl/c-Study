#pragma once
#include <Windows.h>
namespace console_n {
	// 控制台类
	// 控制台信息的实现 1. 绘制当前控制窗口的边界，2.保存窗口的信息，3.清空窗口信息，4。输出窗口信息或者文字
	class SnackConsole
	{
	public:
		// 根据宽度和高度来初始化容器
		// borderSize 边框厚度，默认的是1
		SnackConsole(int width,int height,int borderSize = 1);
		~SnackConsole();

		// 获取控制台句柄 如果存在上级容器，则取上级容器的，如果不存在则取自身的新的；
		HANDLE getHandel() const;

		// 设置父级容器
		void setParent(SnackConsole *parent);

		// 获取父级容器
		SnackConsole * getParent() const;

		// 判断是否有父级容器
		bool  haveParent() const;

		// 获取空闲位置信息
		SMALL_RECT getUnwanted() const; 

	private :
		// 起点 如果父级为空，起点为0，0 ，否则查询父级空闲位置中+边框宽度后进行设置
		COORD start; 
		//终点 同start 
		COORD end; 
		// 父级容器
		const SnackConsole *parent=NULL; 
		HANDLE handle = NULL;
		// 边框厚度
		int borderSize ; 
	
	};


}

