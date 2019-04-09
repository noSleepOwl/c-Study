#pragma once
#include <Windows.h>
namespace console_n {
	// 控制台类
	// 控制台信息的实现 1. 绘制当前控制窗口的边界，2.保存窗口的信息，3.清空窗口信息，4。输出窗口信息或者文字
	class SnackConsole
	{
	public:
		// 构造器，通过构造器进行配置信息 start 左上角起始点， end 左下角结束点 
		// borderSize 边框厚度，默认的是1
		SnackConsole(COORD start,COORD end,int borderSize = 1);
		~SnackConsole();
		// 设置控制台句柄，如果没有设置将从父级中获取如果父级菜单为null 将异常
		// 也就是说，父级容器和 handle 将必须存在一个
		void setHandel(HANDLE handle);  
		// 获取控制台句柄 
		HANDLE getHandel() const;
		// 判断是否有控制台句柄
		bool haveHandel() const;
		// 设置父级容器
		void setParent(SnackConsole *parent);
		// 获取父级容器
		SnackConsole * getParent() const;
		// 判断是否有父级容器
		bool  haveParent() const;
	private :
		// 起点
		COORD start; 
		//终点
		COORD end; 
		// 父级容器
		const SnackConsole *parent=NULL; 
		HANDLE handle = NULL;
		// 边框厚度
		int borderSize ; 
	
	};


}

