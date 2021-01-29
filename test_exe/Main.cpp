#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <stdio.h>

BOOL WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	AllocConsole();
	AttachConsole(GetCurrentProcessId());
	freopen("CON", "w", stdout);

	while (1)
	{
		printf("test\n\n");
		Sleep(1000);
	}

	return 0;
}