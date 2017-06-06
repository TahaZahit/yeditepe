#pragma once
#include <windows.h>

struct
{
	HANDLE hFind;
	WIN32_FIND_DATA data;
	WIN32_FIND_DATA type;
	WIN32_FIND_DATA size;
};
