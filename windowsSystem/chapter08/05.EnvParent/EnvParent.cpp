#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

int _tmain(int argc, TCHAR** argv) {
	SetEnvironmentVariable(_T("Good"), _T("morning"));
	SetEnvironmentVariable(_T("Hey"), _T("Ho! "));
	SetEnvironmentVariable(_T("BIg"), _T("Boy"));

	STARTUPINFO si = { 0, };
	si.cb = sizeof(si);
	PROCESS_INFORMATION pi;
	CreateProcess(NULL, _T("EnvChild.exe"), NULL, NULL, FALSE, CREATE_NEW_CONSOLE | CREATE_UNICODE_ENVIRONMENT, NULL, NULL, &si, &pi);

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	return 0;
}