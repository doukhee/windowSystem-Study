#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <Windows.h>

#define SLOT_NAME		_T("\\\\.\\mailslot\\mailbox")

int _tmain(int argc, TCHAR** argv) {
	HANDLE hMailSlot;
	TCHAR messageBox[50];
	DWORD bytesRead;

	hMailSlot = CreateMailslot(SLOT_NAME, 0, MAILSLOT_WAIT_FOREVER, NULL);

	if (hMailSlot == INVALID_HANDLE_VALUE) {
		_fputts(_T("Unable to create mailslot!\r\n"), stdout);
		return 1;
	}

	_fputts(_T("****************** Message ******************"), stdout);
	while (1) {
		
		if (!ReadFile(hMailSlot, messageBox, sizeof(TCHAR) * 50, &bytesRead, NULL)) {
			_fputts(_T("Unable to Read!\r\n"), stdout);
			CloseHandle(hMailSlot);
			return 1;
		}

		if (!_tcsncmp(messageBox, _T("exit"), 4)) {
			_fputts(_T("Good Bye!\r\n"), stdout);
			break;
		}

		messageBox[bytesRead / sizeof(TCHAR)] = 0;
		_fputts(messageBox, stdout);
		_fputts("\r\n", stdout);
	}
	
	CloseHandle(hMailSlot);

	return 0;
}