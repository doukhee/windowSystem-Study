#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <tchar.h>
#include <Windows.h>

#define STR_LEN					256
#define CMD_TOKEN_NUM			10

TCHAR CmdString[STR_LEN];
TCHAR CmdTokenList[CMD_TOKEN_NUM][STR_LEN];
TCHAR seps[] = _T(" , \t\r\n");

TCHAR ERROR_CMD[] = _T("'%s'은(는) 실행할 수 있는 프로그램이 아닙니다.\r\n");

int CmdProcessing(void);
TCHAR* StrLower(TCHAR*);

int _tmain(int argc, TCHAR** argv) {
	/** 한글 입력을 가능하게 위해 사용되는 함수 */
	_tsetlocale(LC_ALL, _T("Korean"));

	DWORD isExit;
	while (1) {
		isExit = CmdProcessing();
		if (isExit == TRUE) {
			_fputts(_T("명령어 처리를 종료합니다. \r\n"), stdout);
			break;
		}
	}

	return 0;
}

int CmdProcessing() {
	_fputts(_T("Best Command Prompt >> "), stdout);
	/** _getts 대신 보안을 위해 버퍼 갯수 입력을 해주는 _getts_s로 사용해야한다. */
	_getts_s(CmdString, STR_LEN);
	/** 문자열 자르기 */
	TCHAR* token = _tcstok(CmdString, seps);
	int tokeNum = 0;
	while (token != 0) {
		_tcscpy(CmdTokenList[tokeNum++], StrLower(token));
		token = _tcstok(NULL, seps);
	}

	if (!_tcscmp(CmdTokenList[0], _T("exit"))) {
		return TRUE;
	}
	else if (!_tcscmp(CmdTokenList[0], _T("추가 되는 명령어 1"))) {

	}
	else if (!_tcscmp(CmdTokenList[0], _T("추가 되는 명령어 2"))) {

	}
	return 0;
}

TCHAR* StrLower(TCHAR* pStr) {
	TCHAR* ret = pStr;

	while (*pStr) {
		if (_istupper(*pStr)) {
			*pStr = _totlower(*pStr);
		}
		pStr++;
	}
	return ret;
}