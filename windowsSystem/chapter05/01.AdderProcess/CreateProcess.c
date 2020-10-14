#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

#define DIR_LEN			MAX_PATH+1

int _tmain(int argc, TCHAR** argv) {
	/** STARTUPINFO ����ü ������ ����� ���ÿ� 0���� �ʱ�ȭ
	 * CreateProcess()�Լ��� 8��° ���ڷ� �����ϴ� ���μ����� �Ӽ��� �����ϴ� �뵵
	 * �ʱ�ȭ�� 0���� ������Ѵ�.
	 */
	STARTUPINFO si = { 0, };
	PROCESS_INFORMATION pi;
	/** process �Ӽ� ���� */
	/** cb�� Ȯ�强�� ����� ��� */
	si.cb = sizeof(si);
	/** ����ü ������ �����Ǿ� �ִ� ���� �߿��� �ݿ����� �ϴ� ����鿡 ���� ������ ����
	 * STARTF_USEPOSITION�� ����ü ��� �߿��� dwXS�� dwY�� ���� �����ؼ�, �����ϴ� ���μ��� 
	 * ������ ��ġ�� ������ �� ���ȴ�. dwFLags�� STARTF_USEPOSITION�� �����Ǿ� ������, �ǹ̾���.
	 */
	si.dwFlags = STARTF_USEPOSITION | STARTF_USESIZE;
	si.dwX = 100;
	si.dwY = 200;
	/** �����ϴ� ���μ��� �ܼ��� ��ġ�� ������ �ְ� �ִ�.
	 *���μ��� �ܼ� ������ ũ�⸦ ���� ������ ���μ����� ��쿡�� �ǹ� ����.
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

	/** ��Ʈ ������ WInSystem���� ���� */
	//SetCurrentDirectory(_T("C:\\WinSystem"));
	/** ���� ������ �������� �� */
	GetCurrentDirectory(DIR_LEN, cDir);
	/** ���� �۾� ������ console�� ���̱� */
	_fputts(cDir, stdout);
	_fputts(_T("\n"), stdout);
	/** ���μ��� ���� */
	state = CreateProcess(NULL, command, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);

	if (state != 0) {
		_fputts(_T("Creation OK \r\n"), stdout);
		/** process�� memory ������ �������� CloseHandle() �߰� */
		//CloseHandle(pi.hThread);
		//CloseHandle(pi.hProcess);
	}
	else {
		
		_fputts(_T("Creation Error\r\n"), stdout);
		/** process�� memory ������ �������� CloseHandle() �߰� */
		//CloseHandle(pi.hThread);
		//CloseHandle(pi.hProcess);
	}
	return 0;
}