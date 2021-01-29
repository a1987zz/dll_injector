#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <stdio.h>

DWORD WINAPI DllMain(HMODULE, DWORD reason, LPVOID)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		printf("\n\n\ninjected\n\n\n");
	}

	return 0;
}