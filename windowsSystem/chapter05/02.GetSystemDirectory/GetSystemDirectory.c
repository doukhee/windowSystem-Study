#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <Windows.h>


#define DIR_LEN		MAX_PATH + 1

int _tmain(int argc, TCHAR** argv) {
	TCHAR sysDir[DIR_LEN];
	TCHAR winDir[DIR_LEN];
	TCHAR cDir[DIR_LEN];
	/** 시스템의 폴더를 가져오기 */
	GetSystemDirectory(sysDir, DIR_LEN);
	/** 윈도우 폴더를 가져오기 */
	GetWindowsDirectory(winDir, DIR_LEN);
	/** 현재작업 하는 폴더 가져오긴 */
	GetCurrentDirectory(DIR_LEN, cDir);

	_tprintf(_T("System Dir : %s \r\n"), sysDir);
	_tprintf(_T("Windows Dir : %s \r\n"), winDir);
	_tprintf(_T("Current Dir : %s \r\n"), cDir);
	return 0;
}