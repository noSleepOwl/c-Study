
#include "pch.h"
#include "console_tools.h"

HANDLE console_tools::getHandle()
{
	return GetStdHandle(STD_OUTPUT_HANDLE);//获取控制台输入句柄
}

CONSOLE_SCREEN_BUFFER_INFO console_tools::getScreenInfo(HANDLE handle)
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	return info;
}
