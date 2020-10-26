#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

int _tmain(int argc, TCHAR* argv[]) {
	
	STARTUPINFO si = { 0, };
	PROCESS_INFORMATION pi;
	DWORD state;

	si.cb = sizeof(si);
	si.dwFlags = STARTF_USEPOSITION | STARTF_USESIZE;
	si.dwX = 100;
	si.dwY = 200;
	si.dwXSize = 300;
	si.dwYSize = 200;
	si.lpTitle = (LPSTR)_T("Return & Exit");


	TCHAR command[] = _T("OperationStateChild.exe");
	CreateProcess(NULL, command, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);

	for (DWORD i = 0; i < 10000; i++) {
		for (DWORD i = 0; i < 10000; i++);
	}
	//WaitForSingleObject(pi.hProcess, INFINITE);
	GetExitCodeProcess(pi.hProcess, &state);
	if (state == STILL_ACTIVE) {
		_tprintf(_T("STILL_ACTIVE\r\n\r\n"));
	}
	else {
		_tprintf(_T("state : %d \r\n\r\n"));
	}
	CloseHandle(pi.hProcess);
	/** delay를 위한 인자 받는 함수 */
	_gettc(stdin);
	return 0;
}