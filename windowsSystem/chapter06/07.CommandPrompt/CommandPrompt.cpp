#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <locale.h>
#include <Windows.h>

#define STR_LEN				256
#define CMD_TOKEN_NUM		10

TCHAR ERROR_CMD[] = _T("'%s'은(는) 실행할 수 있는 프로그램이 아닙니다.\r\n");

TCHAR cmdString[STR_LEN];
TCHAR cmdTokenList[CMD_TOKEN_NUM][STR_LEN];
TCHAR seps[] = _T(", \t\n");

int CmdReadTokenize(void);
int CmdProcessing(int);
TCHAR* strLower(TCHAR*);

int _tmain(int argc, TCHAR** argv) {
	_tsetlocale(LC_ALL, _T("Korean"));

	if (argc > 2) {
		for (int i = 1; i < argc; i++) {
			_tcscpy(cmdTokenList[i - 1], argv[i]);
		}
		CmdProcessing(argc - 1);
	}
	DWORD isExit = NULL;
	while (1) {
		int tokenNum = CmdReadTokenize();

		if (tokenNum == 0) {
			continue;
		}
		isExit = CmdProcessing(tokenNum);
		if (isExit == TRUE) {
			_fputts(_T("명령어 처리를 종료 합니다. \r\n"), stdout);
			break;
		}
	}
	return 0;
}


int CmdReadTokenize(void) {
	TCHAR* token;

	_fputts(_T("Best Command propmt >> "), stdout);
	_getts_s(cmdString, STR_LEN);

	token = _tcstok(cmdString, seps);

	int tokenNum = 0;

	while (token != NULL) {
		_tcscpy(cmdTokenList[tokenNum++], strLower(token));
		token = _tcstok(NULL, seps);
	}
	return tokenNum;
}

int CmdProcessing(int tokenNum) {
	BOOL isRun;
	STARTUPINFO si = { 0, };
	PROCESS_INFORMATION pi;

	TCHAR CmdStringWithOptions[STR_LEN] = { 0, };
	TCHAR OptString[STR_LEN] = { 0, };

	si.cb = sizeof(si);
	if (!_tcscmp(cmdTokenList[0], _T("exit"))) {
		return TRUE;
	}
	else if (!_tcscmp(cmdTokenList[0], _T("start"))) {
		if (tokenNum > 1) {
			for (int i = 1; i < tokenNum; i++) {
				_stprintf(OptString, _T("%s %s"), OptString, cmdTokenList[i]);
			}
			_stprintf(CmdStringWithOptions, _T("%s %s"), _T("CmdProject.exe"), OptString);
		}
		else {
			_stprintf(CmdStringWithOptions, _T("%s"), _T("CmdProject.exe"));
		}
		isRun = CreateProcess(NULL, CmdStringWithOptions, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
		if (isRun == FALSE) {
			_tprintf(ERROR_CMD, cmdTokenList[0]);
		}
	}
	return 0;	
}

TCHAR* strLower(TCHAR* pStr) {
	TCHAR* ret = pStr;

	while (*pStr) {
		if (_istupper(*pStr)) {
			*pStr = _totlower(*pStr);
		}
		pStr++;
	}
	return ret;
}