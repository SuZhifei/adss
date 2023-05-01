#include "utils/Def.h"
#include <string.h>
#if YT_OS == YT_OS_WINDOWS
#include <Windows.h>
#include <WinBase.h>
#include <TlHelp32.h>
#elif YT_OS == YT_OS_LINUX_X11 || YT_OS == YT_OS_LINUX_ARM || YT_OS == YT_OS_QNX
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#endif

uint64_t alertsCollection::getTickCount()
{
#if YT_OS == YT_OS_WINDOWS
	return ::GetTickCount();
#elif YT_OS == YT_OS_LINUX_X11 || YT_OS == YT_OS_LINUX_ARM || YT_OS == YT_OS_QNX
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
#else
#error "undefined getTickCount on this platform."
#endif
}

std::string alertsCollection::getProcessName(int pid)
{
#if YT_OS == YT_OS_WINDOWS
	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(pe32);
	HANDLE hProcessSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE)
		return "";

	BOOL b = ::Process32First(hProcessSnap, &pe32);
	while (b)
	{
		if (pe32.th32ProcessID == pid)
		{
			::CloseHandle(hProcessSnap);
			return pe32.szExeFile;
		}
		b = ::Process32Next(hProcessSnap, &pe32);
	}
	::CloseHandle(hProcessSnap);
	return "";
#elif YT_OS == YT_OS_LINUX_X11 || YT_OS == YT_OS_LINUX_ARM || YT_OS == YT_OS_QNX
	int BUFFER_SIZE = 1024;
	char ret[BUFFER_SIZE];
	memset(ret, 0, sizeof(ret));
	char pidFilePath[BUFFER_SIZE];
	memset(pidFilePath, 0, sizeof(pidFilePath));
	char buffer[BUFFER_SIZE];
	memset(buffer, 0, sizeof(buffer));
	sprintf(pidFilePath, "/proc/%d/status", pid);
	FILE *f = fopen(pidFilePath, "r");
	if (f)
	{
		if (fgets(buffer, BUFFER_SIZE - 1, f) == NULL)
			fclose(f);

		fclose(f);
		sscanf(buffer, "%*s %s", ret);
		return ret;
	}
	else
	{
		return "";
	}

#else
#error "undefined getProcessName on this platform."
#endif
}
