#include <stdio.h>
#include <string.h>

/** ���ڸ� �Ϲ� ������� �޾Ƽ� ����� �ȵȴ�. */
int main(int argc, char* argv[]) {
	int i;
	for (i = 0; i < argc; i++) {
		/** unicode ����� ��� */
		fputws(argv[i], stdout);
	}
	return 0;
}