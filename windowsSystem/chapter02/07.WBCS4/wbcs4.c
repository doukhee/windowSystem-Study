#include <stdio.h>
#include <string.h>

/** ���� ���� ���ڰ� unicode��� ���� �� unicode ��� main ���� */
int wmain(int argc, wchar_t** argv) {
	for (int i = 0; i < argc; i++) {
		/** unicode ��� ���ڿ� console�� ����ϴ� �Լ� fputws() */
		fputws(argv[i], stdout);
		fputws(L"\n", stdout);
	}

	return 0;
}