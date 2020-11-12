#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

int _tmain(int argc, TCHAR** argv) {
	HANDLE hReadPipe, hWritePipe;

	TCHAR sendString[] = _T("anonymous pipe");
	TCHAR recvString[100];

	DWORD bytesWritten;
	DWORD bytesRead;

	CreatePipe(&hReadPipe, &hWritePipe, NULL, 0);

	WriteFile(hWritePipe, sendString, lstrlen(sendString) * sizeof(TCHAR), &bytesWritten, NULL);
	_tprintf(_T("string send: %s \r\n"), sendString);

	if (!ReadFile(hReadPipe, recvString, bytesWritten, &bytesRead, NULL)) {
		_tprintf(_T("Not Read Pipe\r\n"));
		return 0;
	}
	recvString[bytesRead / sizeof(TCHAR)] = 0;
	_tprintf(_T("string recv : %s \r\n"), recvString);

	CloseHandle(hReadPipe);
	CloseHandle(hWritePipe);
	return 0;
}