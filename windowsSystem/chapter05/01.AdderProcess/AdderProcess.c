#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

int _tmain(int argc, TCHAR** argv) {
	
	DWORD val1, val2;
	/** _ttoi() ���ڿ� �����͸� ������ �����ͷ� �����Ű�� atoi()�Լ��� �����ڵ� ����� _wtoi()�� ���� �����ϱ� ���� ��ũ�� */
	val1 = _ttoi(argv[1]);
	val2 = _ttoi(argv[2]);

	_tprintf(_T("%d + %d = %d \rn"), val1, val2, val1 + val2);
	/** getchar �Լ��� �����ڵ� ����� getwchar �Լ��� ���� �����ϱ� ���� ��ũ�� */
	//_gettchar();
	return 0;
}