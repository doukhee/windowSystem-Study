#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

#define DIR_LEN			MAX_PATH+1

int _tmain(int argc, TCHAR** argv) {
	/** STARTUPINFO 구조체 변수를 선언과 동시에 0으로 초기화
	 * CreateProcess()함수의 8번째 인자로 생성하는 프로세스의 속성을 지정하는 용도
	 * 초기화는 0으로 해줘야한다.
	 */
	STARTUPINFO si = { 0, };
	PROCESS_INFORMATION pi;
	/** process 속성 지정 */
	/** cb는 확장성을 고려한 멤버 */
	si.cb = sizeof(si);
	/** 구조체 변수에 설정되어 있는 값들 중에서 반영코자 하는 멤버들에 대한 정보를 설정
	 * STARTF_USEPOSITION은 구조체 멤버 중에서 dwXS와 dwY의 값을 참조해서, 생성하는 프로세스 
	 * 윈도우 위치를 결정할 때 사용된다. dwFLags에 STARTF_USEPOSITION가 설정되어 있으면, 의미없다.
	 */
	si.dwFlags = STARTF_USEPOSITION | STARTF_USESIZE;
	si.dwX = 100;
	si.dwY = 200;
	/** 생성하는 프로세스 콘솔의 위치를 설정해 주고 있다.
	 *프로세스 콘솔 윈도우 크기를 설정 윈도우 프로세스일 경우에는 의미 없다.
	 */
	si.dwXSize = 300;
	si.dwYSize = 200;
	
	si.lpTitle = _T("I am a boy!");

	TCHAR command[] = _T("AdderProcess.exe 10 20");
	TCHAR cDir[DIR_LEN];
	BOOL state;


	GetCurrentDirectory(DIR_LEN, cDir);
	_fputts(cDir, stdout);
	_fputts(_T("\n"), stdout);

	/** 루트 폴더를 WInSystem으로 변경 */
	//SetCurrentDirectory(_T("C:\\WinSystem"));
	/** 현재 폴더를 가져오는 것 */
	GetCurrentDirectory(DIR_LEN, cDir);
	/** 현재 작업 폴더를 console에 보이기 */
	_fputts(cDir, stdout);
	_fputts(_T("\n"), stdout);
	/** 프로세서 생성 */
	state = CreateProcess(NULL, command, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);

	if (state != 0) {
		_fputts(_T("Creation OK \r\n"), stdout);
		/** process의 memory 누수를 막기위해 CloseHandle() 추가 */
		//CloseHandle(pi.hThread);
		//CloseHandle(pi.hProcess);
	}
	else {
		
		_fputts(_T("Creation Error\r\n"), stdout);
		/** process의 memory 누수를 막기위해 CloseHandle() 추가 */
		//CloseHandle(pi.hThread);
		//CloseHandle(pi.hProcess);
	}
	return 0;
}