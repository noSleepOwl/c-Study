#pragma once
#include <Windows.h>

namespace console_tools {
	inline HANDLE getHandle();
	inline CONSOLE_SCREEN_BUFFER_INFO getScreenInfo(HANDLE handle);
}