#pragma once

#include <windows.h>

#define INJ_ERASE_HEADER				0x0001
#define INJ_FAKE_HEADER					0x0002
#define INJ_UNLINK_FROM_PEB				0x0004
#define INJ_SHIFT_MODULE				0x0008
#define INJ_CLEAN_DATA_DIR				0x0010
#define INJ_THREAD_CREATE_CLOAKED		0x0020
#define INJ_SCRAMBLE_DLL_NAME			0x0040
#define INJ_LOAD_DLL_COPY				0x0080
#define INJ_HIJACK_HANDLE				0x0100

#define INJ_MAX_FLAGS 0x01FF

typedef struct INJECTIONDATA
{
	DWORD			LastErrorCode;
	char			szDllPath[MAX_PATH * 2];
	DWORD			ProcessID;
	DWORD          	Mode;
	DWORD	        Method;
	DWORD			Flags;
	//DWORD			hHandleValue;
	//HINSTANCE		hDllOut;
};

typedef DWORD(__stdcall* fnInject)(INJECTIONDATA*); // int с маленькой буквы отличается от большой Int, Dword - это возвращает значение uint,
 //звездочка * это поинтер в ahk
