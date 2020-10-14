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

TCHAR ERROR_CMD[] = _T("'%s'��(��) ������ �� �ִ� ���α׷��� �ƴմϴ�.\r\n");

int CmdProcessing(void);
TCHAR* StrLower(TCHAR*);

int _tmain(int argc, TCHAR** argv) {
	/** �ѱ� �Է��� �����ϰ� ���� ���Ǵ� �Լ� */
	_tsetlocale(LC_ALL, _T("Korean"));

	DWORD isExit;
	while (1) {
		isExit = CmdProcessing();
		if (isExit == TRUE) {
			_fputts(_T("��ɾ� ó���� �����մϴ�. \r\n"), stdout);
			break;
		}
	}

	return 0;
}

int CmdProcessing() {
	_fputts(_T("Best Command Prompt >> "), stdout);
	/** _getts ��� ������ ���� ���� ���� �Է��� ���ִ� _getts_s�� ����ؾ��Ѵ�. */
	_getts_s(CmdString, STR_LEN);
	/** ���ڿ� �ڸ��� */
	TCHAR* token = _tcstok(CmdString, seps);
	int tokeNum = 0;
	while (token != 0) {
		_tcscpy(CmdTokenList[tokeNum++], StrLower(token));
		token = _tcstok(NULL, seps);
	}

	if (!_tcscmp(CmdTokenList[0], _T("exit"))) {
		return TRUE;
	}
	else if (!_tcscmp(CmdTokenList[0], _T("�߰� �Ǵ� ��ɾ� 1"))) {

	}
	else if (!_tcscmp(CmdTokenList[0], _T("�߰� �Ǵ� ��ɾ� 2"))) {

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