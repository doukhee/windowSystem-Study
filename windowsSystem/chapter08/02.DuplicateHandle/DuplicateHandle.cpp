#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

int _tmain(int argc, TCHAR** argv) {
	HANDLE hProcess;
	TCHAR cmdString[1024];
	
	DuplicateHandle(GetCurrentProcess(), GetCurrentProcess(), GetCurrentProcess(), &hProcess, 0, TRUE, DUPLICATE_SAME_ACCESS);

	_stprintf(cmdString, _T("%s %u"), _T("ChildProcess.exe"), (unsigned)hProcess);

	STARTUPINFO si = { 0, };
	si.cb = sizeof(si);
	PROCESS_INFORMATION pi;

	BOOL isSuccess = CreateProcess(NULL, cmdString, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);

	if (isSuccess == FALSE) {
		_tprintf(_T("Create Process Failed \r\n"));
		return -1;
	}
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	_tprintf(_T("[Parent Process]\r\n"));
	_tprintf(_T("ooooooooooooooooooooooooooopps!\r\n"));

	return 0;
}