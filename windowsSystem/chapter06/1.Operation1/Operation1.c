#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <tchar.h>

int _tmain(int argc, TCHAR** argv) {
	
	STARTUPINFO si = { 0, };
	PROCESS_INFORMATION pi;
	si.cb = sizeof(si);

	TCHAR command[] = _T("Operation2.exe");

	CreateProcess(NULL, command, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);

	while (1) {
		for (DWORD i = 0; i < 10000; i++) {
			for (DWORD i = 0; i < 10000; i++) {
				;
			}
		}
		_fputts(_T("Opertaion1.exe\r\n"), stdout);
	}
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	return 0;
}