#include <stdio.h>
#include <tchar.h>
#include <Windows.h>


int _tmain(int argc, char** argv) {
	SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS);

	while (1) {
		for (DWORD i = 0; i < 10000; i++) {
			for (DWORD i = 0; i < 10000; i++) {
				;
			}
		}
		_fputts(_T("Operation2.exe\r\n"), stdout);
	}
	return 0;
}