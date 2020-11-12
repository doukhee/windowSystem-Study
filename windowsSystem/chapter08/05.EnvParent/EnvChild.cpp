#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

#define BUFSIZE		1024

int _tmain(int argc, TCHAR** argv) {
	TCHAR value[BUFSIZE];
	if (GetEnvironmentVariable(_T("Good"), value, BUFSIZE) > 0) {
		_tprintf(_T("[%s = %s] \r\n"), _T("Good"), value);
	}
	else {
		_tprintf(_T("not Good Key\r\n"));
	}
	if (GetEnvironmentVariable(_T("Hey"), value, BUFSIZE) > 0) {
		_tprintf(_T("[%s = %s] \r\n"), _T("Hey"), value);
	}
	else {
		_tprintf(_T("not Hey key\r\n"));
	}
	if (GetEnvironmentVariable(_T("Big"), value, BUFSIZE) > 0) {
		_tprintf(_T("[%s = %s] \r\n"), _T("Big"), value);
	}
	else {
		_tprintf(_T("not Big key\r\n"));
	}
	Sleep(1000);
	return 0;
}