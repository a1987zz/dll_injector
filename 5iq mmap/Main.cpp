#define _CRT_SECURE_NO_WARNINGS

#include "GH Injector.h"

#include <iostream>
#include <cstring>
#include <fstream>
//#include <Wdm.h>
#include <Windows.h>
#include <TlHelp32.h>

using namespace std;

const char szFilePath[] = "test_.dll";


DWORD FindProcessId(const char* szProcessName) //похожа на получение dword процесса
{
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(PROCESSENTRY32);
	DWORD FoundProcessId = 0;

	while (Process32Next(hSnapshot, &pe32))
	{
		if (!strcmp(szProcessName, pe32.szExeFile))
		{
			FoundProcessId = pe32.th32ProcessID;
			break;
		}
	}

	CloseHandle(hSnapshot);
	return FoundProcessId;
}


int main()
{
	HMODULE hGHInjector = LoadLibraryA("gh_injector.dll");

	fnInject Inject;

	Inject = (fnInject)GetProcAddress(hGHInjector, "InjectA");

	INJECTIONDATA data;
	ZeroMemory(&data, sizeof(INJECTIONDATA));
	data.Mode = 2;
	data.Method = 0;
	data.Flags = INJ_ERASE_HEADER | INJ_SHIFT_MODULE | INJ_UNLINK_FROM_PEB;
	data.ProcessID = FindProcessId("test.exe"); //csgo.exe
	
	/*strcpy(data.szDllPath, szFilePath);*/

	/*memcpy(data.szDllPath, szFilePath, strlen(szFilePath) + 1);*/

	RtlMoveMemory(data.szDllPath, szFilePath, strlen(szFilePath) + 1);

	Inject(&data);

	FreeLibrary(hGHInjector);

	/*Sleep(5000);*/

	return 0;
}